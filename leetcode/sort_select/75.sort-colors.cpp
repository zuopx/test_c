/*75. Sort Colors

https://leetcode.cn/problems/sort-colors/description/?envType=study-plan-v2&envId=top-100-liked

-   遍历两遍，第一遍把0往左移，第二遍把1往左移
-   遍历一遍，把0往左移，把2往右移
*/
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                ++p0;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
                --i;
            }
        }
    }
};