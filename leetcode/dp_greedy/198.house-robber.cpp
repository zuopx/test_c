/*198. 打家劫舍

https://leetcode.cn/problems/house-robber/description/?envType=study-plan-v2&envId=top-100-liked

如果最后一间屋偷了，则前一间不能偷，相当于f(n-2)
如果最后一间屋不偷，则相当于f(n-1)
f(n) = max(f(n-1), f(n-2) + nums[n])
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int f1 = nums[0], f2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            int temp = f2;
            f2 = max(f2, f1 + nums[i]);
            f1 = temp;
        }
        return f2;
    }
};