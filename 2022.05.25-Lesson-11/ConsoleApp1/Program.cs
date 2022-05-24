using System;
/*
https://leetcode.com/problems/palindrome-number/
*/
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            Solution.SIsPalindrome(x);

            Solution sol = new();
            sol.IsPalindrome(x);

            Console.WriteLine(new Solution().IsPalindrome(x) ? "true" : "false"); 
        }
    }
}
