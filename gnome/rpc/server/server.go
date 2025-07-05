package main

import (
	"log"
	"strings"

	"github.com/rabbitmq/amqp091-go"
)

func main() {
	conn, err := amqp091.Dial("amqp://guest:guest@localhost:5673/")
	if err != nil {
		log.Fatalln("Failed to connect to RabbitMQ: ", err)
	}
	defer conn.Close()

	ch, err := conn.Channel()
	if err != nil {
		log.Fatalln("Failed to open a channel: ", err)
	}
	defer ch.Close()

	q, err := ch.QueueDeclare("q.rpc", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare a queue: ", err)
	}

	//Consume messages from the quueue
	msgs, err := ch.Consume(q.Name, "", false, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to register a consumer: ", err)
	}
	log.Println(("RPC Server is waiting for requests..."))

	for msg := range msgs {
		//Process the request (convert text to uppercase)
		procesedText := strings.ToUpper(string(msg.Body))

		log.Printf("Received: %s | responding: %s", msg.Body, procesedText)

		err = ch.Publish("", msg.ReplyTo, false, false, amqp091.Publishing{
			ContentType:   "text/plain",
			CorrelationId: msg.CorrelationId,
			Body:          []byte(procesedText),
		})
		if err != nil {
			log.Fatalln("Failed to send response: ", err)
		}

		msg.Ack(false)
	}
}
