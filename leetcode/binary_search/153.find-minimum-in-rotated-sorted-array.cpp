/**/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int i = 0, j = nums.size();
        int mid, midVal;
        while (i < j)
        {
            mid = (i + j) / 2;
            midVal = nums[mid];
            cout << "(" << i << "," << j << ")" << endl;

            if (midVal > nums[j - 1])
            {
                i = mid + 1;
            }
            else if (midVal < nums[j - 1])
            {
                j = mid + 1;
            }
            else
            {
                if (midVal > nums[i])
                {
                    j = mid;
                }
                else
                {
                    i = mid + 1;
                }
            }
        }

        return midVal;
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 0, 1, 2, 3};
    cout << Solution().findMin(nums) << endl;

    nums = {7, 8, 1, 2, 3, 4, 5, 6};
    cout << Solution().findMin(nums) << endl;

    nums = {3, 1};
    cout << Solution().findMin(nums) << endl;

    cout << "done!" << endl;
    return 0;
}
