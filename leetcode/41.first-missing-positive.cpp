/*41. 缺失的第一个正数

https://leetcode.cn/problems/first-missing-positive/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        int size = nums.size();
        int i = 0;
        int num = 0;
        int tmp = 0;
        while (i < size)
        {
            num = nums[i];
            // cout << "(" << i << "," << num << "),";
            if (num <= 0 || num > size)
            {
                ++i;
                continue;
            }

            if (num == i + 1)
            {
                ++i;
                continue;
            }

            if (num == nums[num - 1])
            {
                i++;
                continue;
            }
            else
            {
                tmp = nums[num - 1];
                nums[num - 1] = num;
                nums[i] = tmp;
            }
        }

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main()
{
    vector<vector<int>> v{
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
    };

    for (auto &nums : v)
    {
        cout << nums[0] << "...: ";
        cout << Solution().firstMissingPositive(nums) << endl;
    }

    cout << "done!" << endl;
    return 0;
}
