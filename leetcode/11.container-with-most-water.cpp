/*11. 盛最多水的容器

https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int r = 0;
        while (i < j)
        {
            r = max(r, min(height[i], height[j]) * (j - i));

            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return r;
    }
};

int main()
{
    vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << Solution().maxArea(nums) << endl;

    return 0;
}
