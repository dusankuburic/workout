
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
            Dictionary<string, int> gradovi = new Dictionary<string, int>()
            {
                {"Beograd",2000000},
                {"Nis",1400000 },
                {"Kraljevo",400000 }
            };


            Console.WriteLine("Grad-Stanovnici");
            foreach (KeyValuePair<string, int> grad in gradovi)
                Console.WriteLine(grad.Key + "-" + grad.Value);


            Console.WriteLine();

            Console.WriteLine("Preko var");
            foreach (var i in gradovi)
                Console.WriteLine(i);

            Console.WriteLine();

            Console.WriteLine("Samo vrednosti");
            foreach (var i in gradovi.Values)
                Console.WriteLine(i);


            Console.WriteLine();

            Console.WriteLine("Samo kljucevi");
            foreach (var i in gradovi.Keys)
                Console.WriteLine(i);



        
            foreach(var i in gradovi)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();


            try
            {
                gradovi.Add("Novi Sad", 340233);
                gradovi.Add("Beograd", 320332);
            }
            catch(ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine();

            Console.WriteLine("Nakon dodavanja");
            foreach(var i in gradovi)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();


            Console.WriteLine(gradovi["Nis"]);

            Console.WriteLine(gradovi["NoviSad"]);


            int brStanovnika;
            bool found = gradovi.TryGetValue("NoviSad", out brStanovnika);

            if (found)
                Console.WriteLine(brStanovnika);
            else
                Console.WriteLine("Ne postoji trazeni kljuc");



            Console.WriteLine("Pre dodavanja:");
            foreach(var i in gradovi)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();

            gradovi.Add("NoviSad", 600000);

            gradovi["Kragujevac"] = 300000;

            gradovi["Beograd"] = 1800000;

            Console.WriteLine("Nakon dodavanja:");
            foreach(var i in gradovi)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine(gradovi.Remove("Nis"));
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }
            Console.WriteLine();


            Console.WriteLine();

            Console.WriteLine(gradovi.Remove("Subotica"));
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }

            Console.ReadKey();
        }
    }
}
