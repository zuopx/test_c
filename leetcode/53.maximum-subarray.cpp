/*53. 最大子数组和

https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxSubArray1(vector<int> &nums)
    {
        vector<int> v{};
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
            v.push_back(sum);
        }
        v.insert(v.begin(), 0);

        int max = INT32_MIN;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                if (v[j] - v[i] > max)
                {
                    max = v[j] - v[i];
                }
            }
        }

        return max;
    }

    int maxSubArray2(vector<int> &nums)
    {

        nums.push_back(-1);
        int max = INT32_MIN;

        int min = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                if (sum - min > max)
                {
                    max = sum - min;
                    // cout << max << ",";
                }
            }
            if (sum < min)
            {
                min = sum;
            }
            sum += nums[i];
        }

        return max;
    }

    /*
    我们用f(i)代表以第i个数结尾的「连续子数组的最大和」

    f(i)=max{f(i−1)+nums[i],nums[i]}
    */
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, ans = nums[0];
        for (auto &num : nums)
        {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {5, 4, -1, 7, 8}, {-1}, {-2, -1}};
    for (auto &nums : v)
    {
        cout << nums[0] << "...: ";
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << "done!" << endl;
    return 0;
}
