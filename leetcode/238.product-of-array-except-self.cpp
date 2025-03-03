/*238. 除自身以外数组的乘积

https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked
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
