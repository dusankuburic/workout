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

	exchangeName := "x.headers.log"
	err = ch.ExchangeDeclare(exchangeName, "headers", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare an exchange:", err)
	}

	queues := []struct {
		name    string
		headers amqp091.Table
	}{
		{name: "q.admin", headers: amqp091.Table{
			"x-match":   "all",
			"user_type": "admin",
		}},
		{name: "q.user", headers: amqp091.Table{
			"x-match":   "all",
			"user_type": "user",
		}},
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

		err = ch.QueueBind(q.Name, "", exchangeName, false, queue.headers)
		if err != nil {
			log.Fatalln("Failed to bind the queue:", err)
		}
	}

	reader := bufio.NewReader(os.Stdin)
	log.Println("Type a message to send to RabbitMQ (type 'quit' to exit):")

	for {
		log.Print("Enter user type [%v/%v]:", queues[0].headers["user_type"], queues[1].headers["user_type"])
		userType, err := reader.ReadString('\n')
		if err != nil {
			log.Fatalln("Unable to read routing key:", err)
		}

		userType = strings.TrimSpace(strings.ToLower(userType))
		if userType == "quit" {
			log.Println("Exiting publisher...")
			break
		}

		if userType != queues[0].headers["user_type"] && userType != queues[1].headers["user_type"] {
			log.Println("Invalid user type. Please enter 'admin' or 'user'.")
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
		err = ch.Publish(exchangeName, "", false, false, amqp091.Publishing{
			ContentType: "text/plain",
			Body:        []byte(input),
			Headers: amqp091.Table{
				"user_type": userType,
			},
		})
		if err != nil {
			log.Fatalln("Failed to publish a message:", err)
		}
		log.Println("Sent: ", input)
	}
}
