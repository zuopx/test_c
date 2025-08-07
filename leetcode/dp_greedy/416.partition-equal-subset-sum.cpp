/*416. Partition Equal Subset Sum

https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked

先计算出数组和，如果和为奇数，则无法平分，如果和为偶数，则将偶数和除以2，得到一个子数组和。
然后尝试从数组中选择元素，使得选择的元素和等于子数组和。
*/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;

        vector<int> v;
        unordered_set<int> s;
        v.push_back(0);
        s.insert(0);
        for (int &num : nums)
        {
            int len = v.size();
            for (int j = 0; j < len; j++)
            {
                if (v[j] + num == target)
                {
                    return true;
                }
                if (v[j] + num < target)
                {
                    if (s.count(v[j] + num) == 0)
                    {
                        s.insert(v[j] + num);
                        v.push_back(v[j] + num);
                    }
                }
            }
        }

        return false;
    }
};