using System;
/*
https://leetcode.com/problems/merge-sorted-array/
*/
namespace ConsoleApp3
{
    class Program
    {
        static void print(int[] arr)
        {
            for (int i = 0; i < arr.Length; ++i)
            {
                Console.Write($"{arr[i]} ");
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            var strarr1 = Console.ReadLine().Split();
            int m = strarr1.Length;
            var strarr2 = Console.ReadLine().Split();
            int n = strarr2.Length;
            int[] arr1 = new int[m + n];
            int[] arr2 = new int[n];
            for (int i = 0; i < n + m; ++i)
            {
                arr1[i] = 0;
            }
            for (int i = 0; i < m; ++i)
            {
                arr1[i] = int.Parse(strarr1[i]);
            }
            for (int i = 0; i < n; ++i)
            {
                arr2[i] = int.Parse(strarr2[i]);
            }

            print(arr1);
            print(arr2);
            Solution sol = new();
            sol.Merge(arr1, m, arr2, n);
            print(arr1);
        }
    }
}
