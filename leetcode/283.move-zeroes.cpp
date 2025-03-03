/*移动零

https://leetcode.cn/problems/move-zeroes/?envType=study-plan-v2&envId=top-100-liked

给定一个数组 nums，编写一个函数将所有 0
移动到数组的末尾，同时保持非零元素的相对顺序。 请注意
，必须在不复制数组的情况下原地对数组进行操作。
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    void moveZeroes1(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i + k < nums.size(); i++)
        {

            if (!nums[i])
            {
                int c = i;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (!nums[j])
                    {
                        continue;
                    }
                    nums[c] = nums[j];
                    nums[j] = 0;
                    c = j;
                }
                k++;
            }
        }
    }

    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;

        for (; j < nums.size(); j++)
        {
            if (!nums[j])
            {
                continue;
            }
            else if (i != j)
            {
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    vector<int> nums{4, 0, 1, 0, 3, 12};

    Solution().moveZeroes(nums);
    for (auto &num : nums)
    {
        cout << num << endl;
    }

    return 0;
}
