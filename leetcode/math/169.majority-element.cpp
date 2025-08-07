/*169. Majority Element

https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int current = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == current)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0) // or count < 0
                {
                    current = nums[i];
                    count = 1;
                }
            }
        }

        return current;
    }
};