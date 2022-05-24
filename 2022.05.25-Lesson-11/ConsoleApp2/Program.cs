using System;
/*
https://leetcode.com/problems/roman-to-integer/
*/
namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var roman = Console.ReadLine();
            Console.WriteLine(new Solution().RomanToInt(roman));
        }
    }
}
