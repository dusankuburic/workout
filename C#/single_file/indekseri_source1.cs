using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp90
{


    class Program
    {

        class KlasaIndeksera
        {
            private string[] niz = new string[5];

            public string this[int indeksniza]
            {
                get
                {
                    return niz[indeksniza];
                }

                set
                {
                    niz[indeksniza] = value;
                }
            }

        }


        class Auto
        {
            public string marka;
            public int godiste;

            public Auto(string m, int g)
            {
                marka = m;
                godiste = g;
            }

            public override string ToString()
            {
                return marka + " " + godiste;
            }
        }


        class Parking: IEnumerable
        {
            private Auto[] niz = new Auto[4];

            public Auto this[int pozicija]
            {
                get { return niz[pozicija]; }
                set { niz[pozicija] = value; }
            }

            public IEnumerator GetEnumerator()
            {
                return niz.GetEnumerator();
            }

        }


        static void Main(string[] args)
        {

            KlasaIndeksera obj = new KlasaIndeksera();

            obj[0] = "prvi";
            obj[1] = "drugi";
            obj[2] = "treci";
            obj[3] = "cetvrti";
            obj[4] = "peti";

            Console.WriteLine("Primer indeksa");
            Console.WriteLine();
            Console.WriteLine("{0}\n{1}\n{2}\n{3}\n{4}\n", obj[0], obj[1], obj[2], obj[3], obj[4]);
            Console.ReadKey();


            Parking parking = new Parking();

            parking[0] = new Auto("Skoda", 2000);
            parking[1] = new Auto("BMW", 2005);
            parking[2] = new Auto("Audi", 2007);
            parking[3] = new Auto("Yugo", 1998);

            Console.WriteLine("Auta na parkingu");
            Console.WriteLine();

            foreach (Auto a in parking)
                Console.WriteLine(a);





            

            Console.ReadKey();
        }
    }
}
