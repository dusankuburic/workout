using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp86
{
    interface IItemManipulation
    {
        void set_name(string name_v);
        string get_name();
        void set_data_of_birth(int date_v);
        int get_date_of_birth();
    }



    class Item
    {
        public string name = "";
        public int value = 0;


        public Item(string name_v, int value_v)
        {
            name = name_v;
            value = value_v;
        }

        public override string ToString()
        {
            return "Name: " + name + " Value: " + value;
        }
    }

    class Hero : IItemManipulation
    {
        private string name;
        private int date_of_birth;
        private List<Item> items;


        public Hero(string name_v, int date_v)
        {

            set_name(name_v);
            set_data_of_birth(date_v);

            items = new List<Item>();
        }


        public void set_name(string name_v)
        {
            if (name_v.Length > 2 || name_v.Length < 40)
                this.name = name_v;
            else
                Console.WriteLine("Name have less then 2 and more then 40 characters");
        }

        public string get_name()
        {
            return this.name;
        }


        public void set_data_of_birth(int date_v)
        {
            if (date_v > 1900 && date_v < DateTime.Now.Year)
                this.date_of_birth = date_v;
            else
                Console.WriteLine("You are not alive");
        }


        public int get_date_of_birth()
        {
            return this.date_of_birth;
        }

        public void add_item(Item item)
        {
            items.Add(item);
        }


        public void print_items()
        {
            foreach (var item in items)
            {
                Console.WriteLine(item);
            }
        }

        public override string ToString()
        {
            return "Name: " + name + " Date of birth: " + date_of_birth + '\n';
        }
    }


    class Army
    {

        public string name;

        private Dictionary<int, List<Hero>> troups;

        public Army(string name_v)
        {
            name = name_v;
            troups = new Dictionary<int, List<Hero>>();

            troups.Add(1, new List<Hero>());
            troups.Add(2, new List<Hero>());
            troups.Add(3, new List<Hero>());
        }


        public void add_hero(int group_index, Hero hero_v)
        {
            troups[group_index].Add(hero_v);
        }

        public void print_whole_army()
        {
            Console.WriteLine("*******************ARMY**********************");
            foreach (var group in troups)
            {
                Console.WriteLine("Group:" + group.Key);
                foreach (Hero h in group.Value)
                    Console.WriteLine("\t" + h);
            }
            Console.WriteLine("*******************END**********************");
        }
    }



    interface IVehicleMovement
    {
        void start();
        void stop();
        void park();
    }


    abstract class Vehicle : IVehicleMovement
    {
        protected int currentSpeed;
        protected int maxSpeed;
        protected bool engineStarted;

        public Army army;

        public abstract void speed_up();

        public void start()
        {
            currentSpeed = 0;
            engineStarted = true;
        }

        public void stop()
        {
            currentSpeed = 0;
        }

        public void park()
        {
            currentSpeed = 0;
            engineStarted = false;
        }
    }


    class Car: Vehicle
    {
        public int date;

        public Car(int d)
        {
            date = d;
            army = new Army("name");
        }

        public override void speed_up()
        {
            if (currentSpeed + 10 <= maxSpeed)
                currentSpeed += 5;
            else
                currentSpeed = maxSpeed;
        }
    }

    class Airplane: Vehicle
    {
        public int wingspan;


        public Airplane(int w_span)
        {
            wingspan = w_span;
            army = new Army("name");
        }


        public override void speed_up()
        {

            if(wingspan > 50)
            {
                if (currentSpeed + 200 <= maxSpeed)
                    currentSpeed += 200;
                else
                    currentSpeed = maxSpeed;
            }
            else
            {
                if (currentSpeed + 40 <= maxSpeed)
                    currentSpeed += 40;
                else
                    currentSpeed = maxSpeed;
            }
        }
    }



    class Program
    {
        static void Main(string[] args)
        {

            Airplane airplane_obj = new Airplane(100);



            airplane_obj.army.add_hero(1, new Hero("Dusan", 1997));
            airplane_obj.army.add_hero(1, new Hero("Jovan", 1997));
            airplane_obj.army.add_hero(2, new Hero("Uros", 1997));
            airplane_obj.army.add_hero(3, new Hero("Lazar", 1997));

            airplane_obj.army.print_whole_army();

            Console.ReadKey();

        }
    }
}
