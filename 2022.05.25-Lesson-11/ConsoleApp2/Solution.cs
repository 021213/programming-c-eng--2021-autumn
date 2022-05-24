using System.Collections.Generic;

namespace ConsoleApp2
{
    class Solution
    {
        private static int[] rr = new int[24] {
            0,0,100,
            500,0,0,
            0,0,1,
            0,0,50,
            1000,0,0,
            0,0,0,
            0,0,0,
            5,0,10};
        private static int A = 'A';
        public int RomanToInt(string s)
        {
            int num = 0;
            int prev = 0;
            for (int i = s.Length - 1; i >= 0; --i)
            {
                int cur = rr[s[i] - A];
                num += cur * (cur >= prev ? 1 : -1);
                prev = cur;
            }
            return num;
        }
    }
}
