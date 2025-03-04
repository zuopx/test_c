/**/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size();
        int mid, midVal;
        while (i < j)
        {
            mid = (i + j) / 2;
            midVal = nums[mid];
            // cout << mid << "," << midVal << endl;

            if (target == midVal)
            {
                return mid;
            }

            if (target < midVal)
            {
                if (midVal <= nums[i] && midVal <= nums[j - 1])
                {
                    j = mid;
                }
                else
                {
                    if (target >= nums[i])
                    {
                        j = mid;
                    }
                    else
                    {
                        i = mid + 1;
                    }
                }
            }
            else if (target > midVal)
            {
                if (midVal >= nums[i])
                {
                    i = mid + 1;
                }
                else
                {
                    if (target <= nums[j - 1])
                    {
                        i = mid + 1;
                    }
                    else
                    {
                        j = mid;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 6) << endl;
    cout << Solution().search(nums, 3) << endl;

    nums = {7, 8, 1, 2, 3, 4, 5, 6};
    cout << Solution().search(nums, 2) << endl;

    nums = {3, 1};
    cout << Solution().search(nums, 3) << endl;

    cout << "done!" << endl;
    return 0;
}
