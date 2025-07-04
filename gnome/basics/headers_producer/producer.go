package main

import (
	"log"
	"time"

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
		log.Fatalln("Failed to pen a channel:", err)
	}
	defer ch.Close()

	exchangeName := "x.headers"

	err = ch.ExchangeDeclare(exchangeName, "headers", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare exchange:", err)
	}

	q1, err := ch.QueueDeclare("queue1", true, false, false, false, amqp091.Table{
		"x-queue-type": "quorum",
	})
	if err != nil {
		log.Fatalln("Failed to declare queue:", err)
	}

	err = ch.QueueBind(q1.Name, "", exchangeName, false, amqp091.Table{
		"x-match": "all",
		"type":    "error",
		"format":  "json",
	})
	if err != nil {
		log.Fatalln("Failed to bind queue1 to exchange:", err)
	}

	q2, err := ch.QueueDeclare("queue2", true, false, false, false, amqp091.Table{
		"x-queue-type": "quorum",
	})
	if err != nil {
		log.Fatalln("Failed to declare queue:", err)
	}

	err = ch.QueueBind(q2.Name, "", exchangeName, false, amqp091.Table{
		"x-match": "any",
		"type":    "warning",
		"format":  "xml",
	})
	if err != nil {
		log.Fatalln("Failed to bind queue2 to exchange:", err)
	}

	messages := []struct {
		body    string
		headers amqp091.Table
	}{
		{"Critical error occurred", amqp091.Table{"type": "error", "format": "json"}},
		{"Warning: low disk space", amqp091.Table{"type": "warning", "format": "xml"}},
		{"Info: system check complete", amqp091.Table{"type": "info", "format": "json"}},
		{"Debug: variable x = 42", amqp091.Table{"type": "info", "format": "JSON"}},
	}

	for _, message := range messages {
		err = ch.Publish(exchangeName, "", false, false, amqp091.Publishing{
			ContentType: "text/plain",
			Body:        []byte(message.body),
			Headers:     message.headers,
		})
		if err != nil {
			log.Fatalln("Failed to publish message:", err)
		}
		log.Println("Sent:", message)
		time.Sleep(time.Second)
	}
}
