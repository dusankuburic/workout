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

	queueNames := []string{"queue1", "queue2"}
	for _, name := range queueNames {

		_, err := ch.QueueDeclare(name, true, false, false, false, amqp091.Table{
			"x-queue-type": "quorum", // arguments1
		})
		if err != nil {
			log.Fatalln("Failed to declare a queue:", err)
		}

		err = ch.QueueBind(name, "", "x.logs", false, nil)
		if err != nil {
			log.Fatalln("Failed to bind the queue:", err)
		}
	}

	reader := bufio.NewReader(os.Stdin)
	var selectedQueue string

	for {
		fmt.Println("Enter the queue name (queue1 or queue2) to consume messages from:")
		input, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Failed to read input:", err)
		}
		input = strings.TrimSpace(input)

		if input == queueNames[0] || input == queueNames[1] {
			selectedQueue = input
			break
		} else {
			fmt.Println("Invalid queue name. Please enter 'queue1' or 'queue2'.")
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
