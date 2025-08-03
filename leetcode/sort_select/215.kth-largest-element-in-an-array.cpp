/*215. 数组中的第K个最大元素

https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include "/home/percy/project/c/test_c/utils.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return findKth(nums, 0, nums.size(), nums.size() + 1 - k);
    }

    int findKth(vector<int> &nums, int start, int end, int k)
    {
        int povit = nums[start];
        int i = start + 1, j = start + 1;
        while (i < end)
        {
            if (nums[i] < povit || (nums[i] == povit && i % 2))
            {
                this->swap(nums, i, j);
                ++j;
            }
            ++i;
        }
        this->swap(nums, start, j - 1);

        if (k == j - start)
        {
            return povit;
        }
        else if (k < j - start)
        {
            return findKth(nums, start, j - 1, k);
        }
        else
        {
            return findKth(nums, j, end, k - (j - start));
        }
    }

    void swap(vector<int> &nums, int i, int j)
    {
        if (i != j)
        {
            int a = nums[i];
            nums[i] = nums[j];
            nums[j] = a;
        }
    }
};

class SolutionUsingHeap
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return 0;
    }
};

int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums, 2) << endl;
    cout << SolutionUsingHeap().findKthLargest(nums, 2) << endl;

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << Solution().findKthLargest(nums, 4) << endl;

    cout << "done!" << endl;
    return 0;
}
