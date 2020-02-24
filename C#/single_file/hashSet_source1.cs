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

            /*
            HashSet<string> gradovi = new HashSet<string>() { "Beograd","Nis","Kragujevac"};

            Console.WriteLine(gradovi.Add("Nis"));
            Console.WriteLine(gradovi.Add("Novi Sad"));

            Console.WriteLine();
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }

            Console.WriteLine(gradovi.Add("NOVI SAD"));
            Console.WriteLine(gradovi.Add("BEOGRAD"));

            Console.WriteLine();
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }

            Console.WriteLine(gradovi.Add("NIS"));
            Console.WriteLine(gradovi.Add("BEOGRAD"));

            Console.WriteLine();
            foreach (var grad in gradovi)
                Console.WriteLine(grad);
    
            */

            HashSet<string> gradovi = new HashSet<string>()
            {"Beograd","Nis","Kragujevac", "Subotica","Novi Sad" };


            Console.WriteLine("HashSet<string> gradovi pre intersectWith");
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }
            Console.WriteLine();

            string[] gradoviNaSeveru = { "Subotica", "Novi Sad" };

            var noviGradovi = gradovi.Intersect(gradoviNaSeveru);
            Console.WriteLine("noviGradovi Nakon Intersect");
            foreach(var grad in noviGradovi)
            {
                Console.WriteLine(grad);
            }
            Console.WriteLine();

            Console.WriteLine("HashSet<string> gradovi Nakon Intersect");
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }
            Console.WriteLine();

            gradovi.IntersectWith(gradoviNaSeveru);

            Console.WriteLine("HashSet<string> gradovi Nakon IntersectWith");
            foreach(var grad in gradovi)
            {
                Console.WriteLine(grad);
            }




            

            Console.ReadKey();
        }
    }
}
