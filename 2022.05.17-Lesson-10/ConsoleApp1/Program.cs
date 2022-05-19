using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int a = int.Parse(input[0]);
            int.TryParse(input[1], out int b);

            long c = (long)b + a;
            Console.WriteLine(c);

            //printf();
            Console.WriteLine("{0}+{1}={2}", a, b, a + b);
            var fstr = $"{a}+{b}={a + b}";
            Console.WriteLine(fstr);
        }
    }
}
