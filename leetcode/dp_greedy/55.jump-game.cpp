/*55. 跳跃游戏

https://leetcode.cn/problems/jump-game/description/?envType=study-plan-v2&envId=top-100-liked

如果末位是可达的，那么任意位置都是可达的。
证明：
-   末位可达，那么必定存在跳跃路径0,i,i+1,i+2...,n-1
-   首先路径上的点是可达的；对于任意两个相邻路径点i,i+1，势必满足i+nums[i]>=i+1，那么i和i+1之间任意点都是可达的。
*/
#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_reach = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > max_reach)
                return false;

            max_reach = max(max_reach, i + nums[i]);
        }

        return true;
    }

    // 缩小问题规模：先找到可跳到end的位置i，然后判断i是否可达
    bool canJump_dp(vector<int> &nums)
    {
        function<bool(int)> dp = [&](int end) -> bool
        {
            if (end <= 0)
                return true;

            for (int i = end - 1; i >= 0; i--)
            {
                if (i + nums[i] >= end)
                {
                    return dp(i);
                }
            }

            return false;
        };

        return dp(nums.size() - 1);
    }
};

// 被测函数包装
bool canJump(vector<int> &nums)
{
    return Solution().canJump_dp(nums);
}

// Test suite for canJump function
class CanJumpTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup code if needed
    }

    void TearDown() override
    {
        // Cleanup code if needed
    }
};

// Test case 1: Empty array - should return true
// 测试用例1：空数组 - 应该返回true
TEST_F(CanJumpTest, EmptyArray)
{
    vector<int> nums = {};
    EXPECT_TRUE(canJump(nums));
}

// Test case 2: Single element array - should return true
// 测试用例2：单个元素数组 - 应该返回true
TEST_F(CanJumpTest, SingleElement)
{
    vector<int> nums = {0};
    EXPECT_TRUE(canJump(nums));

    vector<int> nums2 = {1};
    EXPECT_TRUE(canJump(nums2));
}

// Test case 3: First element is 0 with multiple elements - should return false
// 测试用例3：首元素为0的多元素数组 - 应该返回false
TEST_F(CanJumpTest, FirstElementZero)
{
    vector<int> nums = {0, 1};
    EXPECT_FALSE(canJump(nums));

    vector<int> nums2 = {0, 1, 2};
    EXPECT_FALSE(canJump(nums2));
}

// Test case 4: Can jump to the end - should return true
// 测试用例4：可以跳到末尾 - 应该返回true
TEST_F(CanJumpTest, CanJumpToEnd)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    EXPECT_TRUE(canJump(nums));

    vector<int> nums2 = {1, 1, 1, 1};
    EXPECT_TRUE(canJump(nums2));

    vector<int> nums3 = {3, 2, 1, 0, 4};
    EXPECT_FALSE(canJump(nums3));
}

// Test case 5: Cannot jump to the end - should return false
// 测试用例5：无法跳到末尾 - 应该返回false
TEST_F(CanJumpTest, CannotJumpToEnd)
{
    vector<int> nums = {3, 2, 1, 0, 4};
    EXPECT_FALSE(canJump(nums));

    vector<int> nums2 = {1, 0, 1};
    EXPECT_FALSE(canJump(nums2));

    vector<int> nums3 = {2, 0, 0, 1};
    EXPECT_FALSE(canJump(nums3));
}

// Test case 6: All zeros except last - should return false
// 测试用例6：除了最后一个元素外全为0 - 应该返回false
TEST_F(CanJumpTest, AllZerosExceptLast)
{
    vector<int> nums = {0, 0, 0, 1};
    EXPECT_FALSE(canJump(nums));

    vector<int> nums2 = {1, 0, 0, 1};
    EXPECT_FALSE(canJump(nums2));
}

// Test case 7: All ones - should return true for small arrays
// 测试用例7：全为1的数组 - 小数组应该返回true
TEST_F(CanJumpTest, AllOnes)
{
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_TRUE(canJump(nums));

    vector<int> nums2 = {1, 1};
    EXPECT_TRUE(canJump(nums2));
}

// Test case 8: Large jump at the beginning - should return true
// 测试用例8：开始位置有大跳跃 - 应该返回true
TEST_F(CanJumpTest, LargeFirstJump)
{
    vector<int> nums = {10, 1, 1, 1, 1};
    EXPECT_TRUE(canJump(nums));

    vector<int> nums2 = {5, 0, 0, 0, 0, 0};
    EXPECT_TRUE(canJump(nums2));
}

// Test case 9: Exact jumps needed - should return true
// 测试用例9：需要精确跳跃 - 应该返回true
TEST_F(CanJumpTest, ExactJumps)
{
    vector<int> nums = {1, 1, 1, 1, 0};
    EXPECT_TRUE(canJump(nums));
}

// Test case 10: Edge case with maximum values - performance test
// 测试用例10：最大值边界情况 - 性能测试
TEST_F(CanJumpTest, LargeArrayPerformance)
{
    vector<int> nums(10000, 1);
    nums[0] = 9999;
    EXPECT_TRUE(canJump(nums));
}

// Test case 11: Alternating pattern - should return appropriate result
// 测试用例11：交替模式 - 应该返回适当结果
TEST_F(CanJumpTest, AlternatingPattern)
{
    vector<int> nums = {2, 0, 2, 0, 2};
    EXPECT_TRUE(canJump(nums));

    vector<int> nums2 = {2, 0, 1, 0, 2};
    EXPECT_FALSE(canJump(nums2));
}

// Parameterized test for various scenarios
// 参数化测试用于各种场景
class CanJumpParamTest : public ::testing::TestWithParam<tuple<vector<int>, bool>>
{
};

// Test with multiple parameter sets
// 使用多组参数进行测试
TEST_P(CanJumpParamTest, VariousScenarios)
{
    auto params = GetParam();
    vector<int> nums = get<0>(params);
    bool expected = get<1>(params);
    EXPECT_EQ(expected, canJump(nums));
}

// Test data for parameterized test
// 参数化测试的测试数据
INSTANTIATE_TEST_SUITE_P(
    CanJumpTests,
    CanJumpParamTest,
    ::testing::Values(
        make_tuple(vector<int>{2, 3, 1, 1, 4}, true),  // Can jump
        make_tuple(vector<int>{3, 2, 1, 0, 4}, false), // Cannot jump
        make_tuple(vector<int>{0}, true),              // Single element
        make_tuple(vector<int>{1, 0}, true),           // Two elements, can jump
        make_tuple(vector<int>{0, 1}, false),          // Two elements, cannot jump
        make_tuple(vector<int>{1, 1, 1, 1}, true),     // All ones
        make_tuple(vector<int>{2, 0, 0}, true),        // Exact jump
        make_tuple(vector<int>{1, 0, 1}, false)        // Cannot reach end
        ));

// Test fixture with custom assertions
// 带自定义断言的测试夹具
class CanJumpAdvancedTest : public ::testing::Test
{
protected:
    // Custom assertion for jump game
    // 跳跃游戏的自定义断言
    void AssertCanJump(const vector<int> &nums, bool expected)
    {
        bool result = canJump(const_cast<vector<int> &>(nums));
        ASSERT_EQ(expected, result)
            << "Failed for input: " << ::testing::PrintToString(nums);
    }
};

// Advanced test cases with custom assertions
// 使用自定义断言的高级测试用例
TEST_F(CanJumpAdvancedTest, CustomAssertions)
{
    AssertCanJump({}, true);
    AssertCanJump({0}, true);
    AssertCanJump({0, 1}, false);
    AssertCanJump({2, 3, 1, 1, 4}, true);
    AssertCanJump({3, 2, 1, 0, 4}, false);
}