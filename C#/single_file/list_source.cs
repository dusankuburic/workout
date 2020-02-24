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


            List<int> godine = new List<int>() { 2009, 2010, 2011, 2012, 2013, 2014 };

            Console.WriteLine("Pre dodavanja:");
            Console.WriteLine("Broj elemenata: " + godine.Count);
            Console.WriteLine("Kapacitet: " + godine.Capacity);
            Console.WriteLine();

            godine.Add(2015);
            godine.Add(2016);
            godine.Add(2017);

            Console.WriteLine("Nakon dodavanja:");
            Console.WriteLine("Broj elemenata: " + godine.Count);
            Console.WriteLine("Kapacitet: " + godine.Capacity);
            Console.WriteLine();


            foreach (int god in godine)
                Console.WriteLine(god);


            godine.Add(2010);
            godine.Add(2010);

            godine.Remove(2010);
            godine.RemoveAt(3);
            godine.RemoveRange(4, 2);

            Console.WriteLine("Nakon uklanjanja");
            Console.WriteLine("Broj elemenata:" + godine.Count);
            Console.WriteLine("Kapacitet:" + godine.Capacity);

            Console.WriteLine();

            foreach (int god in godine)
                Console.WriteLine(god);



            List<int> brojevi = new List<int>() { 2009, 2010, 2011 };


            brojevi.Insert(2, 2011);
            Console.WriteLine("Nakon umetanja:");
            foreach(int broj in brojevi)
            {
                Console.WriteLine(broj);

            }
            Console.WriteLine();


            brojevi.InsertRange(brojevi.Count, new List<int>() { 2013, 2014, 2015 });
            Console.WriteLine("Nakon InsertRange:");
            
            foreach(int broj in brojevi)
            {
                Console.WriteLine(broj);
            }

            Console.WriteLine();


            Console.ReadKey();
        }
    }
}
