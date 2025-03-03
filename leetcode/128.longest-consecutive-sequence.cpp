/*最长连续序列

https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked

给定一个未排序的整数数组 nums
，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
    输入：nums = [100,4,200,1,3,2]
    输出：4
    解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
    输入：nums = [0,3,7,2,5,8,4,6,0,1]
    输出：9
示例 3：
    输入：nums = [1,0,1,2]
    输出：3
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestConsecutive1(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int a = 1, r = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                a++;
                if (a > r)
                {
                    r = a;
                }
                continue;
            }
            else if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                a = 1;
            }
        }

        return r;
    }

    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto &num : nums)
        {
            s.insert(num);
        }

        int r = 0, a = 0;
        for (auto num : s)
        {
            if (s.count(num - 1))
            {
                continue;
            }

            a = 1;
            while (s.count(num + 1))
            {
                a++;
                num++;
            }
            if (a > r)
            {
                r = a;
            }
        }

        return r;
    }
};

int main()
{
    vector<int> nums{1, 0, 1, 2};
    int r = Solution().longestConsecutive(nums);
    cout << r << endl;

    return 0;
}
