/*接雨水

https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-100-liked

有的题是不知道方法，有的题是不知道实现，这道题属于前者。
需找到规律：每个位置能接水的单位数等于两边最大高度中的较小值减去当前高度。
*/
#include <gtest/gtest.h>
#include <vector>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        if (height.empty())
            return 0;

        int n = height.size();
        if (n <= 2)
            return 0;

        std::vector<int> leftMax(n, 0);
        std::vector<int> rightMax(n, 0);

        // 计算每个位置左边的最大值
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        // 计算每个位置右边的最大值
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }

        // 计算雨水总量
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int waterLevel = std::min(leftMax[i], rightMax[i]);
            if (waterLevel > height[i])
            {
                result += waterLevel - height[i];
            }
        }

        return result;
    }
};

// 被测函数
int trap(std::vector<int> &height)
{
    return Solution().trap(height);
}

// Test suite for trap function
class TrapTest : public ::testing::Test
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

// Test case 1: Empty array should return 0
// 测试用例1：空数组应返回0
TEST_F(TrapTest, EmptyArrayReturnsZero)
{
    std::vector<int> height = {};
    EXPECT_EQ(0, trap(height));
}

// Test case 2: Single element array should return 0
// 测试用例2：单个元素数组应返回0
TEST_F(TrapTest, SingleElementReturnsZero)
{
    std::vector<int> height = {1};
    EXPECT_EQ(0, trap(height));
}

// Test case 3: Two elements array should return 0
// 测试用例3：两个元素数组应返回0
TEST_F(TrapTest, TwoElementsReturnsZero)
{
    std::vector<int> height = {1, 2};
    EXPECT_EQ(0, trap(height));
}

// Test case 4: Typical trap scenario
// 测试用例4：典型接雨水场景
TEST_F(TrapTest, TypicalTrapScenario)
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(6, trap(height));
}

// Test case 5: Increasing sequence should return 0
// 测试用例5：递增序列应返回0（无法接雨水）
TEST_F(TrapTest, IncreasingSequenceReturnsZero)
{
    std::vector<int> height = {1, 2, 3, 4, 5};
    EXPECT_EQ(0, trap(height));
}

// Test case 6: Decreasing sequence should return 0
// 测试用例6：递减序列应返回0（无法接雨水）
TEST_F(TrapTest, DecreasingSequenceReturnsZero)
{
    std::vector<int> height = {5, 4, 3, 2, 1};
    EXPECT_EQ(0, trap(height));
}

// Test case 7: Equal heights should return 0
// 测试用例7：相等高度应返回0（无法接雨水）
TEST_F(TrapTest, EqualHeightsReturnsZero)
{
    std::vector<int> height = {2, 2, 2, 2};
    EXPECT_EQ(0, trap(height));
}

// Test case 8: V-shape structure
// 测试用例8：V型结构应能接雨水
TEST_F(TrapTest, VShapeStructure)
{
    std::vector<int> height = {5, 1, 1, 1, 5};
    EXPECT_EQ(12, trap(height)); // (5-1)*3 = 12
}

// Test case 9: Peak shape structure
// 测试用例9：峰型结构
TEST_F(TrapTest, PeakShapeStructure)
{
    std::vector<int> height = {1, 5, 1, 1, 1, 5, 1};
    EXPECT_EQ(12, trap(height)); // 左边V型4个单位 + 右边V型8个单位 = 12
}

// Test case 10: All zeros should return 0
// 测试用例10：全零数组应返回0
TEST_F(TrapTest, AllZerosReturnsZero)
{
    std::vector<int> height = {0, 0, 0, 0};
    EXPECT_EQ(0, trap(height));
}

// Test case 11: Complex scenario with multiple traps
// 测试用例11：复杂多陷阱场景
TEST_F(TrapTest, ComplexMultipleTraps)
{
    std::vector<int> height = {3, 0, 2, 0, 4};
    EXPECT_EQ(7, trap(height)); // 左边陷阱3个单位 + 右边陷阱4个单位 = 7
}

// Test case 12: Large values
// 测试用例12：大数值测试
TEST_F(TrapTest, LargeValues)
{
    std::vector<int> height = {10000, 0, 10000};
    EXPECT_EQ(10000, trap(height)); // 中间可以接10000单位雨水
}

// Test case 13: Many elements with simple pattern
// 测试用例13：多元素简单模式
TEST_F(TrapTest, ManyElementsSimplePattern)
{
    std::vector<int> height = {2, 0, 0, 0, 2};
    EXPECT_EQ(6, trap(height)); // 中间4个位置各接1.5单位？实际应该是6单位
    // 实际计算：每个位置能接 min(2,2) - 0 = 2 单位，共3个位置，总计6单位
}

// Test case 14: No trap scenario - flat terrain
// 测试用例14：平地形无陷阱场景
TEST_F(TrapTest, FlatTerrainNoTrap)
{
    std::vector<int> height = {3, 3, 3, 3, 3};
    EXPECT_EQ(0, trap(height));
}

// Test case 15: Edge case with maximum possible trap
// 测试用例15：最大可能陷阱的边界情况
TEST_F(TrapTest, MaximumTrapEdgeCase)
{
    std::vector<int> height = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int expected = 9; // 9个中间位置，每个位置接1单位雨水
    EXPECT_EQ(expected, trap(height));
}