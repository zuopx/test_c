/*189. 轮转数组

https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<int> v{nums};
        // for (auto &num : nums)
        // {
        //     v.push_back(num);
        // }

        k = k % size;
        for (int i = 0; i < size; ++i)
        {
            // cout << (i - k + size) % size << ",";
            nums[i] = v[(i - k + size) % size];
        }
        cout << "; ";
    }
};

int main()
{
    vector<pair<vector<int>, int>> v{
        {{1, 2, 3, 4, 5, 6, 7}, 3},
        {{-1, -100, 3, 99}, 2},
    };
    for (auto &p : v)
    {
        cout << p.first[0] << "...," << p.second << ": ";
        Solution().rotate(p.first, p.second);
        for (auto &i : p.first)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << "done!" << endl;
    cout << (8 % 7) << endl;
    return 0;
}
