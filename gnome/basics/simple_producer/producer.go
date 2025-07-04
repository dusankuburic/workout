package main

import (
	"bufio"
	"log"
	"os"
	"strings"

	"github.com/rabbitmq/amqp091-go"
)

func main() {

	//connect to rabbitmq

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

	err = ch.ExchangeDeclare("x.logs", "fanout", true, false, false, false, nil)
	if err != nil {
		log.Fatalln("Failed to declare an exchange:", err)
	}

	// declare a queue1
	q1, err := ch.QueueDeclare(
		"queue1", // name of the queue
		true,     // durable
		false,    // delete when unused
		false,    // exclusive
		false,    // no-wait
		amqp091.Table{
			"x-queue-type": "quorum", // arguments
		}, // arguments,
	)
	if err != nil {
		log.Fatalln("Failed to declare a queue:", err)
	}

	err = ch.QueueBind(q1.Name, "", "x.logs", false, nil)
	if err != nil {
		log.Fatalln("Failed to bind the queue:", err)
	}

	// declare a queue2
	q2, err := ch.QueueDeclare(
		"queue2", // name of the queue
		true,     // durable
		false,    // delete when unused
		false,    // exclusive
		false,    // no-wait
		amqp091.Table{
			"x-queue-type": "quorum", // arguments
		}, // arguments,
	)
	if err != nil {
		log.Fatalln("Failed to declare a queue:", err)
	}

	err = ch.QueueBind(q2.Name, "", "x.logs", false, nil)
	if err != nil {
		log.Fatalln("Failed to bind the queue:", err)
	}

	// log.Println("Stopping RabbitMQ continer")
	// cmd := exec.Command("docker", "stop", "rabbitmq1")
	// err = cmd.Run()
	// if err != nil {
	// 	log.Fatalln("Failed to stop RabbitMQ container:", err)
	// }

	//time.Sleep(time.Second)

	// ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
	// defer cancel()

	//msg := "Hello rabbitmq!"

	reader := bufio.NewReader(os.Stdin)
	log.Println("Type a message to send to RabbitMQ (type 'quit' to exit):")

	for {
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
		err = ch.Publish("x.logs", "", false, false, amqp091.Publishing{
			ContentType: "text/plain",
			Body:        []byte(input),
		})
		if err != nil {
			log.Fatalln("Failed to publish a message:", err)
		}
		log.Println("Sent: ", input)
	}
}
