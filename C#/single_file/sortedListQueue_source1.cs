using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp90
{


    class Program
    {

        static void Main(string[] args)
        {

            LinkedList<string> android = new LinkedList<string>();

            android.AddFirst("Ice Cream SandWich");
            android.AddLast("Marshmallow");
            android.AddBefore(android.First, "Lollipop");
            android.AddAfter(android.First, "Jelly Bean");
            android.AddAfter(android.Find("Jelly Bean"), "Kit Kat");


            foreach(var node in android)
            {
                Console.WriteLine(node);
            }
            Console.WriteLine();

            android.RemoveFirst();
            android.RemoveLast();
            android.Remove("Lollipop");

            Console.WriteLine("Nakon uklanjanja");
            foreach(var node in android)
            {
                Console.WriteLine(node);
            }


            Stack<string> kutijaKnjiga = new Stack<string>();
            kutijaKnjiga.Push("Harry Potter");
            kutijaKnjiga.Push("Lord of the Rings");
            kutijaKnjiga.Push("Hunger Games");

            foreach(var item in kutijaKnjiga)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();
            Console.WriteLine("Izvadjen element:" + kutijaKnjiga.Pop());

            Console.WriteLine();
            foreach(var item in kutijaKnjiga)
            {
                Console.WriteLine(item);
            }



            Queue<string> redBanka = new Queue<string>();
            redBanka.Enqueue("Nikola");
            redBanka.Enqueue("Stefan");
            redBanka.Enqueue("Milos");

            foreach(var item in redBanka)
            {
                Console.WriteLine(item);
            }


            Console.WriteLine();

            Console.WriteLine("Pozvan u kancelariju: " + redBanka.Dequeue());

            Console.WriteLine();
            foreach(var item in redBanka)
            {
                Console.WriteLine(item);
            }

            Console.ReadKey();
        }
    }
}
