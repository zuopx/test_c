/*31. Next Permutation

https://leetcode.cn/problems/next-permutation/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (is_sorted(nums.begin(), nums.end(), greater<int>()))
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                for (int j = nums.size() - 1; j > i; j--)
                {
                    if (nums[j] > nums[i])
                    {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }
    }
};