package main

import (
	"log"

	"github.com/rabbitmq/amqp091-go"
)

func main() {

	conn, err := amqp091.Dial("amqp://guest:guest@localhost:5673/")
	if err != nil {
		log.Fatalln("Failed to connect to RabbitMQ:", err)
	}
	defer conn.Close()

	ch, err := conn.Channel()
	if err != nil {
		log.Fatalln("Failed to open a channel:", err)
	}
	defer ch.Close()

	exchangeName := "x.auto.delete"
	err = ch.ExchangeDeclare(exchangeName, "fanout", true, true, false, false, nil)
	if err != nil {
		log.Fatalln("Failed top declare exchange:", err)
	}

	q, err := ch.QueueDeclare("", true, true, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare a queue:", err)
	}

	ch.QueueBind(q.Name, "", exchangeName, false, nil)
	if err != nil {
		log.Fatalln("Failed to bind queue to exchange:", err)
	}

	msgs, err := ch.Consume(q.Name, "ashish", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to register a consumer:", err)
	}

	log.Println("Waiting for messages.")
	for msg := range msgs {
		log.Println("Received:", string(msg.Body))
	}

}
