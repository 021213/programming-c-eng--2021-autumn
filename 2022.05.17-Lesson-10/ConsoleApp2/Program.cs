using System;
using System.Collections;

namespace ConsoleApp2
{
    class Program
    {
        static void changeArray(int[] a)
        {
            for (int i = 0; i < a.Length; ++i)
            {
                a[i] = a.Length - i;
            }
        }
        static void printArray(int[] a)
        {
            for (int i = 0; i < a.Length; ++i)
            {
                Console.Write($"{a[i]} ");
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            int[] a = new int[10];
            for(int i = 0; i < a.Length; ++i)
            {
                a[i] = i;
            }
            printArray(a);
            changeArray(a);
            printArray(a);
        }
    }
}
