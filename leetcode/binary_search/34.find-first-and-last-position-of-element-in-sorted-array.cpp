/*34. 在排序数组中查找元素的第一个和最后一个位置

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, float target)
    {
        int i = 0, j = nums.size();
        int mid, midVal;
        while (i < j)
        {
            mid = (i + j) / 2;
            midVal = nums[mid];

            if (target == midVal)
            {
                return mid;
            }
            else if (target < midVal)
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        if (target < midVal)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{-1, -1};

        if (nums.empty())
        {
            return ans;
        }

        int left = searchInsert(nums, target - 0.1);
        if (left >= nums.size() || nums[left] != target)
        {
            return ans;
        }

        int right = searchInsert(nums, target + 0.1);
        ans[0] = left;
        ans[1] = right - 1;

        return ans;
    }
};

int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};

    vector<int> ans;

    ans = Solution().searchRange(nums, 8);
    cout << ans[0] << "," << ans[1] << endl;

    ans = Solution().searchRange(nums, 6);
    cout << ans[0] << "," << ans[1] << endl;

    cout << "done!" << endl;
    return 0;
}
