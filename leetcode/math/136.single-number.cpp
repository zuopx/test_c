/*136. Single Number

https://leetcode.cn/problems/single-number/description/?envType=study-plan-v2&envId=top-100-liked

异或运算：nums[i] ^ nums[i] = 0
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};