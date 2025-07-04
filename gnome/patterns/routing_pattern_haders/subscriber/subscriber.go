package main

import (
	"bufio"
	"fmt"
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

	queues := []string{"q.user", "q.admin"}
	for _, queue := range queues {

		_, err := ch.QueueDeclare(
			queue, // name of the queue
			true,  // durable
			false, // delete when unused
			false, // exclusive
			false, // no-wait
			amqp091.Table{
				"x-queue-type": "quorum",
			},
		)
		if err != nil {
			log.Fatalln("Failed to declare a queue:", err)
		}
	}

	reader := bufio.NewReader(os.Stdin)
	var selectedQueue string

	for {
		fmt.Printf("Enter the queue name to consumer from (options: %v/%v):", queues[0], queues[1])
		input, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Failed to read input:", err)
		}
		input = strings.TrimSpace(input)

		if input == queues[0] || input == queues[1] {
			selectedQueue = input
			break
		} else {
			fmt.Println("Invalid queue name. Please enter 'q.error' or 'q.info'.")
		}
	}

	fmt.Println("Listening on queue:", selectedQueue)
	msgs, err := ch.Consume(selectedQueue, "", false, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to register a consumer:", err)
	}

	for msg := range msgs {
		log.Printf("Received: %s", msg.Body)

		msg.Ack(false)
	}
}
