/*4. 寻找两个正序数组的中位数

https://leetcode.cn/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        if ((m + n) % 2)
        {
            return findKth(nums1, nums2, (m + n) / 2 + 1); // 9个数，找第5个
        }
        else
        {
            // 10个数，找第5个和第6个
            return (findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }

    int findKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        return helper(nums1, 0, nums2, 0, k);
    }

    // k只减不增
    int helper(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k)
    {
        cout << "(" << start1 << "," << start2 << ")";
        if (start1 >= nums1.size())
        {
            return nums2[start2 + k - 1];
        }
        else if (start2 >= nums2.size())
        {
            return nums1[start1 + k - 1];
        }

        if (k == 1)
        {
            return min(nums1[start1], nums2[start2]);
        }

        int step = k / 2;
        int end1 = min(start1 + step, (int)nums1.size());
        int end2 = min(start2 + step, (int)nums2.size());

        if (nums1[end1 - 1] < nums2[end2 - 1])
        {
            return helper(nums1, end1, nums2, start2, k - (end1 - start1));
        }
        else
        {
            return helper(nums1, start1, nums2, end2, k - (end2 - start2));
        }
    }
};

int main()
{
    vector<int> nums1{1, 3, 5, 7, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    vector<int> nums2{2, 4, 6, 8, 10};

    for (int k = 0; k < nums1.size() + nums2.size(); ++k)
    {
        cout << k + 1 << ":" << Solution().findKth(nums1, nums2, k + 1) << endl;
    }

    // Solution().findMedianSortedArrays1(nums1, nums2);

    cout << "done!" << endl;
    return 0;
}
