/**/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        int mid1, mid2;
        int val1, val2;
        int left1 = 0, left2 = 0, right1 = nums1.size() - 1, right2 = nums2.size() - 1;
        int haft1, haft2, haft;

        while (right1 > left1 && right2 > left2)
        {
            cout << left1 << "," << right1 << ";" << left2 << "," << right2 << endl;

            mid1 = (left1 + right1) / 2;
            mid2 = (left2 + right2) / 2;
            val1 = nums1[mid1];
            val2 = nums2[mid2];

            if (val1 >= val2)
            {
                haft1 = right1 - mid1;
                haft2 = mid2 - left2;
                haft = min(haft1, haft2);
                right1 = right1 - haft;
                left2 = left2 + haft;
            }
            else
            {
                haft1 = mid1 - left1;
                haft2 = right2 - mid2;
                haft = min(haft1, haft2);
                left1 = left1 + haft;
                right2 = right2 - haft;
            }

            cout << haft << endl;
            if (haft == 0)
            {
                break;
            }
        }

        return 0;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        if ((m + n) % 2)
        {
            return findKth(nums1, nums2, (m + n) / 2);
        }
        else
        {
            return (findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }

    int findKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        return helper(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k);
    }

    int helper(vector<int> &nums1, int left1, int right1, vector<int> &nums2, int left2, int right2, int k)
    {
        int mid1 = (left1 + right1) / 2;
        int mid2 = (left2 + right2) / 2;
        int val1 = nums1[mid1], val2 = nums2[mid2];

        if (val1 < val2)
        {
            if (mid1 - left1 < k)
            {
                
            }
        }
    }
};

int main()
{
    vector<int> nums1{1, 3, 5, 7, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    vector<int> nums2{2, 4, 6, 8, 10};

    Solution().findMedianSortedArrays(nums1, nums2);

    cout << 5 / 2 << "," << 5 / 2.0 << endl;

    cout << "done!" << endl;
    return 0;
}
