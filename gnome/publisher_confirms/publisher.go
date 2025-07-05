package main

import (
	"log"

	"github.com/rabbitmq/amqp091-go"
)

func main() {
	// Connect to RabbitMQ
	conn, err := amqp091.Dial("amqp://guest:guest@localhost:5673/")
	if err != nil {
		log.Fatal("Failed to connect to RabbitMQ:", err)
	}
	defer conn.Close()

	// Create a channel
	ch, err := conn.Channel()
	if err != nil {
		log.Fatal("Failed to open a channel:", err)
	}
	defer ch.Close()

	ch.Confirm(false)
	if err != nil {
		log.Fatal("Failed to enable publisher confirms:", err)
	}

	// Declare the queue (same as producer)
	q, err := ch.QueueDeclare(
		"q.task", // Queue name
		true,     // Durable
		false,    // Auto-delete
		false,    // Exclusive
		false,    // No-wait
		nil,      // Arguments
	)
	if err != nil {
		log.Fatal("Failed to declare a queue:", err)
	}

	// Publish a message
	body := "Hello, RabbitMQ with Publisher Confirms!"
	err = ch.Publish(
		"",     // Default exchange
		q.Name, // Routing key (queue name)
		false,  // Mandatory
		false,  // Immediate
		amqp091.Publishing{
			ContentType: "text/plain",
			Body:        []byte(body),
		},
	)
	if err != nil {
		log.Fatal("Failed to publish a message:", err)
	}

	//Wait for confirmation
	confirmed := <-ch.NotifyPublish(make(chan amqp091.Confirmation, 1))

	log.Println("Delivery Tag:", confirmed.DeliveryTag)

	if confirmed.Ack {
		log.Println("Message confirmed by RabbitMQ")
	} else {
		log.Println("Message not confirmed by RabbitMQ")
	}
}
