package main

import (
	"bufio"
	"crypto/rand"
	"fmt"
	"log"
	"os"
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

	//Declare a temoirary queue for the RPC response
	q, err := ch.QueueDeclare(
		"",    // Use an empty name to create a temporary queue
		false, // Not durable
		false, // Exclusive to this connection
		true,  // Exclusive to this connection
		false, // Not a wait for the queue to be deleted
		nil,   // No additional arguments
	)
	if err != nil {
		log.Fatalln("Failed to declare a temporary queue: ", err)
	}

	// Generate a unique correlation ID for the request
	corrIDBytes := make([]byte, 16)
	_, err = rand.Read(corrIDBytes)
	if err != nil {
		log.Fatalln("Failed to generate correlation ID: ", err)
	}
	corrID := fmt.Sprintf("%x", corrIDBytes)
	println(corrID)

	reader := bufio.NewReader(os.Stdin)
	log.Println("Type a message to send to RabbitMQ (type 'quit' to exit):")

	for {
		log.Println("Enter message:")
		input, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Failed to read string: ", err)
		}

		input = strings.TrimSpace(input)

		if strings.ToLower(input) == "quit" {
			log.Println("Exiting client")
			break
		}

		err = ch.Publish("", "q.rpc", false, false, amqp091.Publishing{
			ContentType:   "text/plain",
			CorrelationId: corrID,
			ReplyTo:       q.Name,
			Body:          []byte(input),
		})
		if err != nil {
			log.Fatalln("Unable to publish message: ")
		}

		log.Println("Sent: ", input)

		msgs, err := ch.Consume(q.Name, "", true, false, false, false, nil)
		if err != nil {
			log.Fatalln("Failed to register a consumer: ", err)
		}

		for msg := range msgs {
			if msg.CorrelationId == corrID {
				log.Println("Received response: ", string(msg.Body))
				break
			}
		}
	}

}
