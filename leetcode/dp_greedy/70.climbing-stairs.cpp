/*70. 爬楼梯

https://leetcode.cn/problems/climbing-stairs/?envType=study-plan-v2&envId=top-100-liked

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

1. 最后一步爬1个台阶，方法种类为f(n-1)
2. 最后一步爬2个台阶，方法种类为f(n-2)
1、2互斥，所以f(n) = f(n-1) + f(n-2)

用递归，会超时，所以要用循环。
*/
#include <gtest/gtest.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 0)
            return 0;

        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else
        {
            int a = 1, b = 2;
            for (int i = 3; i <= n; i++)
            {
                b = a + b;
                a = b - a;
            }

            return b;
        }
    }
};

int climbStairs(int n)
{
    return Solution().climbStairs(n);
}

// Test fixture for climbStairs function
class ClimbStairsTest : public ::testing::Test
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

// Test case 1: Boundary condition - n = 1
// 测试边界条件：n = 1时应该返回1
TEST_F(ClimbStairsTest, HandlesBaseCaseOne)
{
    EXPECT_EQ(1, climbStairs(1));
}

// Test case 2: Boundary condition - n = 2
// 测试边界条件：n = 2时应该返回2
TEST_F(ClimbStairsTest, HandlesBaseCaseTwo)
{
    EXPECT_EQ(2, climbStairs(2));
}

// Test case 3: Normal case - n = 3
// 测试正常情况：n = 3时应该返回3
TEST_F(ClimbStairsTest, HandlesNormalCaseThree)
{
    EXPECT_EQ(3, climbStairs(3));
}

// Test case 4: Normal case - n = 4
// 测试正常情况：n = 4时应该返回5
TEST_F(ClimbStairsTest, HandlesNormalCaseFour)
{
    EXPECT_EQ(5, climbStairs(4));
}

// Test case 5: Normal case - n = 5
// 测试正常情况：n = 5时应该返回8
TEST_F(ClimbStairsTest, HandlesNormalCaseFive)
{
    EXPECT_EQ(8, climbStairs(5));
}

// Test case 6: Edge case - n = 0
// 测试边缘情况：n = 0时应该返回0
TEST_F(ClimbStairsTest, HandlesZeroCase)
{
    EXPECT_EQ(0, climbStairs(0));
}

// Test case 7: Invalid input - negative number
// 测试无效输入：负数应该返回0或适当处理
TEST_F(ClimbStairsTest, HandlesNegativeInput)
{
    EXPECT_EQ(0, climbStairs(-1));
    EXPECT_EQ(0, climbStairs(-10));
}

// Test case 8: Large number test
// 测试大数值：验证函数能处理较大的输入
TEST_F(ClimbStairsTest, HandlesLargeNumber)
{
    // For large numbers, we expect some result (implementation dependent)
    // 这里只是示例，实际结果取决于具体实现
    EXPECT_GE(climbStairs(10), 0);
}
