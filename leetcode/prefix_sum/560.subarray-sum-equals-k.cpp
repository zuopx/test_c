/*560. 和为 K 的子数组

https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int r = 0;

        unordered_map<int, vector<int>> m;

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            m[sum].push_back(i);
        }

        sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(k + sum) != m.end())
            {
                for (auto &j : m[k + sum])
                {
                    if (j >= i)
                    {
                        ++r;
                    }
                }
            }

            sum += nums[i];
        }
        return r;
    }
};

int main()
{
    vector<tuple<vector<int>, int>> v{{{1, 1, 1}, 2}, {{1, 2, 3}, 3}};
    for (auto &t : v)
    {
        cout << Solution().subarraySum(get<0>(t), get<1>(t)) << endl;
    }
    cout << "done!" << endl;
    return 0;
}
