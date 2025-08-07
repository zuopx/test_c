/*152. Maximum Product Subarray

https://leetcode.cn/problems/maximum-product-subarray/description/?envType=study-plan-v2&envId=top-100-liked

f(n)：以nums[n]结尾的子数组乘积的最大值
f(n) = max(f(n-1) * nums[n], nums[n]) 仅限于 nums 为非负数

fmax(n): 以nums[n]结尾的子数组乘积的最大值
fmin(n): 以nums[n]结尾的子数组乘积的最小值
fmax(n) = max(fmax(n-1) * nums[n], fmin(n-1) * nums[n], nums[n])
fmin(n) = min(fmax(n-1) * nums[n], fmin(n-1) * nums[n], nums[n])
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = 1;
            for (int j = i; j < nums.size(); j++)
            {
                temp *= nums[j];
                res = max(res, temp);
            }
        }

        return res;
    }

    int maxProduct2(vector<int> &nums)
    {
        int res = nums[0];

        int fmin = 1, fmax = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = fmax, b = fmin;
            fmax = max(nums[i], max(a * nums[i], b * nums[i]));
            fmin = min(nums[i], min(a * nums[i], b * nums[i]));

            res = max(res, fmax);
        }

        return res;
    }
};
