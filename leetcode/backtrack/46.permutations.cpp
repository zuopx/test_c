/*46. 全排列

https://leetcode.cn/problems/permutations/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    stack<int> st{};
    stack<int> st1{};
    unordered_set<int> s{};

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        helper(nums, ans);

        return ans;
    }

    void helper(vector<int> &nums, vector<vector<int>> &ans)
    {
        if (s.size() == nums.size())
        {
            vector<int> v{};
            st1 = st;
            while (!st1.empty())
            {
                v.push_back(st1.top());
                st1.pop();
            }
            ans.push_back(v);
            for (auto &num : v)
            {
                cout << num << ",";
            }
            cout << endl;
            return;
        }

        for (auto &num : nums)
        {
            if (s.find(num) == s.end())
            {
                s.insert(num);
                st.push(num);
                helper(nums, ans);
                st.pop();
                s.erase(num);
            }
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3};

    Solution().permute(nums);

    cout << "done!" << endl;
    return 0;
}
