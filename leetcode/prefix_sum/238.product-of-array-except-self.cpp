/*238. 除自身以外数组的乘积

https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/

#include <array>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> p1{size, 0}, p2{size, 0};
        for (int i = 0; i < size; ++i)
        {
            if (i == 0)
            {
                p1[i] = nums[i];
                p2[size - 1 - i] = nums[size - 1 - i];
            }
            else
            {
                p1[i] = nums[i] * p1[i - 1];
                p2[size - 1 - i] = nums[size - 1 - i] * p2[size - 1 - i + 1];
            }
        }

        vector<int> r;
        for (int i = 0; i < size; ++i)
        {
            if (i == 0)
            {
                r.push_back(p2[i + 1]);
            }
            else if (i == size - 1)
            {
                r.push_back(p1[i - 1]);
            }
            else
            {
                r.push_back(p1[i - 1] * p2[i + 1]);
            }
        }

        return r;
    }

    std::vector<int> productExceptSelf2(std::vector<int> &nums)
    {
        std::vector<int> answer(nums.size(), 1);
        int left = 0, right = nums.size() - 1;
        int lp = 1, rp = 1;
        while (right >= 0 && left < nums.size())
        {
            answer[right] *= rp;
            answer[left] *= lp;
            lp *= nums[left++];
            rp *= nums[right--];
        }
        return answer;
    }
};
int main()
{
    vector<vector<int>> v{{1, 2, 3, 4}, {-1, 1, 0, -3, 3}};
    for (auto &nums : v)
    {
        cout << nums[0] << "...: ";
        auto r = Solution().productExceptSelf(nums);
        for (auto &i : r)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << "done!" << endl;
    return 0;
}
