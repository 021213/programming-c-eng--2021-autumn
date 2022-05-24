using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Solution
    {
        public void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            int ind1 = m - 1;
            int ind2 = n - 1;
            for(int i = n + m - 1; i >= 0; --i)
            {
                if ((ind1 >= 0) && ((ind2 < 0) || (nums1[ind1] >= nums2[ind2])))
                {
                    nums1[i] = nums1[ind1];
                    ind1--;
                }
                else
                {
                    nums1[i] = nums2[ind2];
                    ind2--;
                }
            }
        }
    }
}
