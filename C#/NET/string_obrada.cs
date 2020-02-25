using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp91
{
    class Program
    {


        static void Main(string[] args)
        {

            char c = 'A';
            char newLine = '\n';

            Console.WriteLine(System.Char.ToUpper('c'));
            Console.WriteLine(char.IsWhiteSpace('\t'));


            string s1 = "Hello";
            string s2 = "Frist Line\r\nSecond Line";
            string s3 = @"\\server\fileshare\helloworld.cs";

            Console.WriteLine(new string('*', 10));


            char[] ca = "Hello".ToCharArray();
            string s = new string(ca);


            /*
            string empty = "";
            Console.WriteLine(empty == "");
            Console.WriteLine(empty == string.Empty);
            Console.WriteLine(empty.Length == 0);

            string nullString = null;
            Console.WriteLine(nullString == null);
            Console.WriteLine(nullString == "");
            Console.WriteLine(nullString.Length == 0);
            */

            string str = "abcde";
            char letter = str[1];

            foreach (char ch in "123")
                Console.WriteLine(ch + " ");


            Console.WriteLine("quick brown fox".Contains("brown"));
            Console.WriteLine("quick brown fox".EndsWith("fox"));


            Console.WriteLine("abcde".IndexOf("CD", StringComparison.CurrentCultureIgnoreCase));

            Console.WriteLine("ab,cd ef".IndexOfAny(new char[] { ' ', ',' }));
            Console.WriteLine("pas5w0rd".IndexOfAny("0123456789".ToCharArray()));


            string left3 = "123245".Substring(0, 3);
            string mid3 = "12345".Substring(1, 3);

            string end3 = "12345".Substring(2);

            string sa1 = "helloworld".Insert(5, ", ");
            string sa2 = sa1.Remove(5, 2);


            Console.WriteLine("12345".PadLeft(9, '*'));
            Console.WriteLine("12345".PadLeft(9));


            Console.WriteLine("   abc \t\r\n".Trim().Length);

            Console.WriteLine("to be done".Replace(" ", " | "));
            Console.WriteLine("to be done".Replace(" ", " "));

            string[] words = "The quick brown fox".Split();


            foreach (string word in words)
                Console.Write(word + "|");


            string[] words1 = "The quick brown fox".Split();
            string together = string.Join(" ", words1);

            string sentence = string.Concat("The", " quick", " brown", " fox");
            string sameSentence = "The" + " quick" + " brown" + " fox";


            string composite = "It's {0} degrees in {1} on this {2} morning";
            string sf = string.Format(composite, 35, "Perth", DateTime.Now.DayOfWeek);


            string comp = "Name={0,-20} Credit Limit={1,15:C}";

            Console.WriteLine(string.Format(composite, "Mary", 500));
            Console.WriteLine(string.Format(composite, "Elizabeth", 20000));


            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 50; i++)
                sb.Append(i + " ");

            Console.WriteLine(sb.ToString());

            Console.ReadKey();
        }
    }
}

