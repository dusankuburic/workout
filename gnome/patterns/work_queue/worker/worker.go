package main

import (
	"log"
	"time"

	"github.com/rabbitmq/amqp091-go"
)

func main() {

	conn, err := amqp091.Dial("amqp://guest:guest@localhost:5673/")
	if err != nil {
		log.Fatalln("Failed to connect to RagbbitMQ:", err)
	}
	defer conn.Close()

	ch, err := conn.Channel()
	if err != nil {
		log.Fatalln("Failed to open a channel:", err)
	}
	defer ch.Close()

	q, err := ch.QueueDeclare("task_queue", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare queue:", err)
	}

	msgs, err := ch.Consume(q.Name, "", false, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to register a consumer:", err)
	}

	log.Println("Worker is waiting for messages...")
	for msg := range msgs {
		log.Printf("Received a message: %s", msg.Body)
		time.Sleep(time.Duration(len(msg.Body)) * time.Millisecond * 300) // Simulate work
		log.Println("Done: ", string(msg.Body))

		msg.Ack(false) // Acknowledge the message
	}
}
