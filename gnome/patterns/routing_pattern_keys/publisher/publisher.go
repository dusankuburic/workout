package main

import (
	"bufio"
	"log"
	"os"
	"strings"

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

	err = ch.ExchangeDeclare("x.logs", "direct", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare an exchange:", err)
	}

	queues := []struct {
		name string
		key  string
	}{
		{name: "q.error", key: "error"},
		{name: "q.info", key: "info"},
	}
	for _, queue := range queues {

		q, err := ch.QueueDeclare(
			queue.name, // name of the queue
			true,       // durable
			false,      // delete when unused
			false,      // exclusive
			false,      // no-wait
			amqp091.Table{
				"x-queue-type": "quorum",
			},
		)
		if err != nil {
			log.Fatalln("Failed to declare a queue:", err)
		}

		err = ch.QueueBind(q.Name, queue.key, "x.logs", false, nil)
		if err != nil {
			log.Fatalln("Failed to bind the queue:", err)
		}
	}

	reader := bufio.NewReader(os.Stdin)
	log.Println("Type a message to send to RabbitMQ (type 'quit' to exit):")
	log.Println("Routing keys options: 'error', 'info'")

	for {
		log.Print("Enter routing key (error/info):")
		routingKey, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Unable to read routing key:", err)
		}

		routingKey = strings.TrimSpace(strings.ToLower(routingKey))
		if routingKey == "quit" {
			log.Println("Exiting publisher...")
			break
		}

		if routingKey != queues[0].key && routingKey != queues[1].key {
			log.Println("Invalid routing key. Please enter 'error' or 'info'.")
			continue
		}

		log.Print("Enter message:")
		input, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Unable to read string:", err)
		}
		input = strings.TrimSpace(input)

		if strings.ToLower(input) == "quit" {
			log.Println("Exiting producer.")
			break
		}

		log.Println("Attempting to publish message...")
		err = ch.Publish("x.logs", routingKey, false, false, amqp091.Publishing{
			ContentType: "text/plain",
			Body:        []byte(input),
		})
		if err != nil {
			log.Fatalln("Failed to publish a message:", err)
		}
		log.Println("Sent: ", input)
	}
}
