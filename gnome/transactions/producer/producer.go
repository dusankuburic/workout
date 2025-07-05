package main

import (
	"bufio"
	"log"
	"os"
	"strings"

	"github.com/rabbitmq/amqp091-go"
)

func main() {
	// Connect to RabbitMQ
	conn, err := amqp091.Dial("amqp://guest:guest@localhost:5673/")
	if err != nil {
		log.Fatal("Failed to connect to RabbitMQ:", err)
	}
	defer conn.Close()

	// Open a channel
	ch, err := conn.Channel()
	if err != nil {
		log.Fatal("Failed to open a channel:", err)
	}
	defer ch.Close()

	// Declare a queue
	q, err := ch.QueueDeclare(
		"q.transaction", // Queue name
		false,           // Durable
		false,           // Auto-delete
		false,           // Exclusive
		false,           // No-wait
		nil,             // Arguments
	)
	if err != nil {
		log.Fatal("Failed to declare a queue:", err)
	}

	err = ch.Tx()
	if err != nil {
		log.Fatal("Failed to start transaction:", err)
	}
	log.Println("Transaction started...")

	reader := bufio.NewReader(os.Stdin)
	log.Println("Type a message to send to RabbitMQ (type 'quit' to exit)")
	log.Println("Messages will be sent as transaction type commit or rollback.")
	for {
		log.Print("Enter message:")
		input, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Unable to read string:", err)
		}
		input = strings.ToLower(strings.TrimSpace(input))

		if input == "quit" {
			log.Println("Exiting producer.")
			break
		}

		if input == "rollback" {
			log.Println("Message is rollback, rolling back trasaction...")
			err = ch.TxRollback()
			if err != nil {
				log.Fatalln("Failed to rollback the transaction:", err)
			}
			log.Println("Transaction rolled back. Messages not published.")
			return
		}

		if input == "commit" {
			log.Println("Message is commit, committing transaction...")
			err = ch.TxCommit()
			if err != nil {
				log.Fatalln("Failed to commit the transaction:", err)
			}
			log.Println("Transaction commited. Messages published.")
			break
		}

		err = ch.Publish("", q.Name, false, false, amqp091.Publishing{
			DeliveryMode: amqp091.Persistent,
			ContentType:  "text/plain",
			Body:         []byte(input),
		})
		if err != nil {
			log.Println("Failed to publish message:, rolling back", err)
			ch.TxRollback()
			log.Fatalln("Transaction rolled back. Message not published.")
		}

		log.Println("Sent:", input)
	}
}
