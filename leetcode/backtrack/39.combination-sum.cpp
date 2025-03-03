/*39. 组合总和*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> nums{};
        for (int i = 0; i < candidates.size(); ++i)
        {
            nums.push_back(0);
        }

        helper(candidates, nums, 0, 0, target, ans);

        return ans;
    }

    void helper(vector<int> candidates, vector<int> &nums, int idx, int sum, int &target, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            vector<int> v;
            for (int i = 0; i < idx; ++i)
            {
                if (candidates[i])
                {
                    int candidate = candidates[i] / nums[i];
                    for (int j = 0; j < nums[i]; ++j)
                    {
                        v.push_back(candidate);
                        cout << candidate << ",";
                    }
                }
            }
            cout << endl;
            ans.push_back(v);
            return;
        }
        if (idx == candidates.size() || sum > target)
        {
            return;
        }

        int candidate = candidates[idx];
        int num = nums[idx];
        int i = 0;
        while (1)
        {
            candidates[idx] = i * candidate;
            nums[idx] = i;
            if (sum + candidates[idx] > target)
            {
                break;
            }
            helper(candidates, nums, idx + 1, sum + candidates[idx], target, ans);
            ++i;
        }
        candidates[idx] = candidate;
        nums[idx] = num;
    }
};

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    Solution().combinationSum(candidates, 7);
    cout << "done!" << endl;
    return 0;
}
