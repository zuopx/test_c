/*35. 搜索插入位置

https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        int mid, midVal;
        while (i < j)
        {
            mid = (i + j) / 2;
            midVal = nums[mid];

            if (target == midVal)
            {
                return mid;
            }
            else if (target < midVal)
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        if (target < midVal)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};

int main()
{
    vector<int> nums{1, 3, 5, 6};
    cout << Solution().searchInsert(nums, 5) << endl;
    cout << Solution().searchInsert(nums, 2) << endl;
    cout << Solution().searchInsert(nums, 7) << endl;

    cout << "done!" << endl;
    return 0;
}
