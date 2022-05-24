using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Solution
    {
        public bool IsPalindrome(int x)
        {
            if (x < 0)
            {
                return false;
            }
            int strX = x;
            int revX = 0;
            while (x != 0)
            {
                revX = revX * 10 + (x % 10);
                x /= 10;
            }
            return (revX == strX);
        }
        static public bool SIsPalindrome(int x)
        {
            if (x < 0)
            {
                return false;
            }
            int strX = x;
            int revX = 0;
            while (x != 0)
            {
                revX = revX * 10 + (x % 10);
                x /= 10;
            }
            return (revX == strX);
        }
    }
}
