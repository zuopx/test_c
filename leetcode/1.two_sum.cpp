/*两数之和

https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值
target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。

示例 1：
    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
    输入：nums = [3,2,4], target = 6
    输出：[1,2]
示例 3：
    输入：nums = [3,3], target = 6
    输出：[0,1]

提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
*/

#include <unordered_map>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    // 暴力求解
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        int i, j;
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>{i, j};
                }
            }
        }

        return vector<int>{-1, -1};
    }

    // 使用哈希表
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        int i, j;
        for (i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                return vector<int>{m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }

        return vector<int>{-1, -1};
    }
};

// 测试用例
TEST(TwoSumTest, BasicTest)
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> expected = {0, 1};
    EXPECT_EQ(Solution().twoSum(nums, 9), expected);
}

TEST(TwoSumTest, MiddleMatch)
{
    vector<int> nums = {3, 2, 4};
    vector<int> expected = {1, 2};
    EXPECT_EQ(Solution().twoSum(nums, 6), expected);
}

TEST(TwoSumTest, DuplicateNumbers)
{
    vector<int> nums = {3, 3};
    vector<int> expected = {0, 1};
    EXPECT_EQ(Solution().twoSum(nums, 6), expected);
}

TEST(TwoSumTest, NoSolution)
{
    vector<int> nums = {1, 5, 3};
    vector<int> expected = {-1, -1};
    EXPECT_EQ(Solution().twoSum(nums, 10), expected);
}

TEST(TwoSumTest, NegativeNumbers)
{
    vector<int> nums = {-1, -2, 3};
    vector<int> expected = {1, 2};
    EXPECT_EQ(Solution().twoSum(nums, 1), expected);
}

TEST(TwoSumTest, SingleElement)
{
    vector<int> nums = {5};
    vector<int> expected = {-1, -1};
    EXPECT_EQ(Solution().twoSum(nums, 10), expected);
}

TEST(TwoSumTest, MultipleSolutions)
{
    vector<int> nums = {2, 5, 5, 11};
    vector<int> expected = {1, 2};
    EXPECT_EQ(Solution().twoSum(nums, 10), expected);
}
