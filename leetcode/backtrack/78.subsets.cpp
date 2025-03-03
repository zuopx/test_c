/*78. 子集*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans{};
        helper(nums, 0, ans);
        return ans;
    }

    void helper(vector<int> &nums, int idx, vector<vector<int>>& ans)
    {
        if (idx == nums.size())
        {
            vector<int> subset{};
            for (auto &num : nums)
            {
                if (num != INT32_MAX)
                {
                    subset.push_back(num);
                    cout << num << ",";
                }
            }
            cout << endl;
            ans.push_back(subset);
            return;
        }

        helper(nums, idx + 1, ans);

        int num = nums[idx];
        nums[idx] = INT32_MAX;
        helper(nums, idx + 1, ans);
        nums[idx] = num;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    auto ans = Solution().subsets(nums);
    cout << "done!" << endl;
    return 0;
}
