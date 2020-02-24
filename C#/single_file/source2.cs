using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp90
{

    public class Auto : IComparable
    {

        private int god;
        private string proizv;

        public Auto(string Proizvodjac, int Godina)
        {
            proizv = Proizvodjac;
            god = Godina;
        }

        public int Godina
        {
            get { return god; }
            set { god = value; }
        }

        public string Proizvodjac
        {
            get { return proizv; }
            set { proizv = value; }
        }

        private class sortGodinaRastuci: IComparer<Auto>
        {
            int IComparer<Auto>.Compare(Auto x, Auto y)
            {
                if (x.god > y.god)
                    return 1;

                if (x.god < y.god)
                    return -1;
                else
                    return 0;
            }
        }

        private class sortGodinaOpadajuci: IComparer<Auto>
        {
            int IComparer<Auto>.Compare(Auto x, Auto y)
            {
                if (x.god < y.god)
                    return 1;

                if (x.god > y.god)
                    return -1;
                else
                    return 0;
            }
        }


        private class sortProizvodjacOpadajuci: IComparer<Auto>
        {
            int IComparer<Auto>.Compare(Auto x, Auto y)
            {
                return String.Compare(x.proizv, y.proizv);
            }
        }


        int IComparable.CompareTo(object obj)
        {
            Auto c = (Auto)obj;
            return String.Compare(this.proizv, c.proizv);
        }

        public static IComparer<Auto> sortYearAscending()
        {
            return (IComparer<Auto>)new sortGodinaRastuci();
        }

        public static IComparer<Auto> sortYearDescending()
        {
            return (IComparer<Auto>)new sortGodinaOpadajuci();
        }

        public static IComparer<Auto> sortMakeDescending()
        {
            return (IComparer<Auto>)new sortProizvodjacOpadajuci();
        }
  
    }



    class Program
    {
        static void UnosAuta(Auto c)
        {
            Console.WriteLine("Unesi podatke o automobilima:");
            Console.Write("Proizvodjac: ");
            c.Proizvodjac = Console.ReadLine();
            Console.Write("Godina proizvodnje");
            c.Godina = int.Parse(Console.ReadLine());
        }

        static void IspisAuta(Auto[] nizAutomobila)
        {
            foreach(Auto c in nizAutomobila)
            {
                Console.WriteLine(c.Proizvodjac + "\t\t" + c.Godina);
            }
        }


        static void Main(string[] args)
        {

            int i, n;

            Console.WriteLine("Uneti broj automobila\n");
            n = int.Parse(Console.ReadLine());
            Auto[] nizAutomobila = new Auto[n];

            for(i = 0; i < n; i++)
            {
                nizAutomobila[i] = new Auto("", 0);
                UnosAuta(nizAutomobila[i]);
                Console.WriteLine();
            }


            Console.WriteLine();
            Console.WriteLine("Nesortirani niz\n");
            IspisAuta(nizAutomobila);

            Array.Sort(nizAutomobila, Auto.sortYearAscending());
            Console.WriteLine("\n Niz sortiran prema godini proizvodnje (rastuci poredak)\n");
            IspisAuta(nizAutomobila);

            Console.WriteLine("\nNiz sortiran prema proizvodjacu (opadajuci poredak)\n");
            Array.Sort(nizAutomobila, Auto.sortMakeDescending());
            IspisAuta(nizAutomobila);

            Array.Sort(nizAutomobila, Auto.sortYearDescending());
            Console.WriteLine("\nNiz sortiran prema godini proizvodnje (opadajuci poredak)\n");
            IspisAuta(nizAutomobila);
           


             Console.ReadKey();

        }
    }
}
