using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp90
{

    public abstract class Artikal
    {
        protected string naziv;
        protected int cena;

        public Artikal(string n, int c)
        {
            naziv = n;
            cena = c;
        }

        public virtual float prodajnaCena()
        {
            return cena;
        }

        public override string ToString()
        {
            return "Naziv: " + naziv + " Cena: " + prodajnaCena();
        }

        private class sortirajPoImenuAsc : IComparer<Artikal>
        {
            int IComparer<Artikal>.Compare(Artikal x, Artikal y)
            {
                return x.naziv.CompareTo(y.naziv);
            }
        }

        public static IComparer<Artikal> sortPoImenuAsc()
        {
            return (IComparer<Artikal>)new sortirajPoImenuAsc();
        }

        private class sortirajPoCeniAsc : IComparer<Artikal>
        {
            int IComparer<Artikal>.Compare(Artikal x, Artikal y)
            {
                return x.prodajnaCena().CompareTo(y.prodajnaCena());
            }
        }

        public static IComparer<Artikal> sortPoCeniAsc()
        {
            return (IComparer<Artikal>)new sortirajPoCeniAsc();
        }
    }


    class Pice: Artikal
    {
        protected float prAlkohola;

        public Pice(string n, int c, float pr):
            base(n,c)
        {
            prAlkohola = pr;
        }

        public override float prodajnaCena()
        {
            return (1 + prAlkohola / 100f) * cena;
        }

        public override string ToString()
        {
            return base.ToString() + " PrAlkohola: " + prAlkohola;
        }
    }


    class Hrana: Artikal
    {
        protected float preostaliRokUpotrebe;

        public Hrana(string n, int c, float preos):
            base(n, c)
        {
            preostaliRokUpotrebe = preos;
        }

        public override float prodajnaCena()
        {
            if (preostaliRokUpotrebe < 10)
                return cena * 0.6f;
            else
                return base.prodajnaCena();
        }

        public override string ToString()
        {
            return base.ToString() + " PreostaliRokUpotrebe: " + preostaliRokUpotrebe;
        }
    }

    interface IKupovina
    {
        void dodaj(Artikal a);
        float ukupnaCena();
    }

    class Korpa: IKupovina
    {
        private List<Artikal> la;

        public Korpa()
        {
            la = new List<Artikal>();
        }

        void IKupovina.dodaj(Artikal a)
        {
            la.Add(a);
        }

        float IKupovina.ukupnaCena()
        {
            float ukupno = 0F;

            foreach (Artikal pom in la)
                ukupno += pom.prodajnaCena();

            return ukupno;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            la.Sort(Artikal.sortPoCeniAsc());
            sb.AppendLine("Sadrzaj korpe:");

            foreach(Artikal a in la)
            {
                sb.AppendLine("\t" + a.ToString());
            }

            sb.AppendLine("Ukupna cena: " + ((IKupovina)this).ukupnaCena().ToString());

            return sb.ToString();
        }
    }


    class Program
    {

        static void Main(string[] args)
        {
            Artikal a1 = new Pice("Pivo", 45, 5f);
            Artikal a2 = new Hrana("Hleb", 55,1);
            Artikal a3 = new Hrana("Smoki", 60, 100);

            IKupovina k = new Korpa();

            k.dodaj(a1);
            k.dodaj(a2);
            k.dodaj(a3);

            Console.WriteLine(k);

             Console.ReadKey();

        }
    }
}
