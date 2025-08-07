/*121. 买卖股票的最佳时机

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-100-liked

买股票为场景应用，第一步，通过建模把它还原为算法题：对于数组，找出每个元素后的最大元素。
建立状态转移方程：f(n)表示位置n及其后所有元素的最大值，f(n-1) = max(f(n), nums[n-1])
*/
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:

    // 第i天买，最高点卖
    int maxProfit(vector<int> &prices)
    {
        vector<int> topPrices(prices.size());
        int res = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            topPrices[i] = i == prices.size() - 1 ? prices[i] : max(prices[i], topPrices[i + 1]);
            res = max(res, topPrices[i] - prices[i]);
        }

        return res;
    }

    // 优化版
    int maxProfit1(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int topPrice = prices.back();
        int res = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            topPrice = max(prices[i], topPrice);
            res = max(res, topPrice - prices[i]);
        }

        return res;
    }

    // 第i天卖，最低点买
    int maxProfit2(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int res = 0;
        int minPrice = prices.front();
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
        }

        return res;
    }
};

int maxProfit(vector<int> &prices)
{
    return Solution().maxProfit2(prices);
}

// Unit Test Design for maxProfit function
// 单元测试设计说明：
// 1. 测试边界条件：空数组、单元素数组
// 2. 测试特殊情况：价格持续下跌
// 3. 测试正常情况：价格持续上涨、价格波动
// 4. 验证函数返回正确的最大利润值

class MaxProfitTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // 测试前的初始化工作
    }

    void TearDown() override
    {
        // 测试后的清理工作
    }
};

// Test Case 1: Empty array - 空数组测试
// Input: {}
// Expected Output: 0
TEST_F(MaxProfitTest, EmptyArray)
{
    vector<int> prices = {};
    EXPECT_EQ(0, maxProfit(prices));
}

// Test Case 2: Single element array - 单元素数组测试
// Input: {1}
// Expected Output: 0
TEST_F(MaxProfitTest, SingleElement)
{
    vector<int> prices = {1};
    EXPECT_EQ(0, maxProfit(prices));
}

// Test Case 3: Two elements increasing - 两元素递增测试
// Input: {1, 2}
// Expected Output: 1
TEST_F(MaxProfitTest, TwoElementsIncreasing)
{
    vector<int> prices = {1, 2};
    EXPECT_EQ(1, maxProfit(prices));
}

// Test Case 4: Two elements decreasing - 两元素递减测试
// Input: {2, 1}
// Expected Output: 0
TEST_F(MaxProfitTest, TwoElementsDecreasing)
{
    vector<int> prices = {2, 1};
    EXPECT_EQ(0, maxProfit(prices));
}

// Test Case 5: Continuously decreasing prices - 持续下跌价格测试
// Input: {7, 6, 4, 3, 1}
// Expected Output: 0
TEST_F(MaxProfitTest, ContinuouslyDecreasing)
{
    vector<int> prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(0, maxProfit(prices));
}

// Test Case 6: Continuously increasing prices - 持续上涨价格测试
// Input: {1, 2, 3, 4, 5}
// Expected Output: 4 (5-1=4)
TEST_F(MaxProfitTest, ContinuouslyIncreasing)
{
    vector<int> prices = {1, 2, 3, 4, 5};
    EXPECT_EQ(4, maxProfit(prices));
}

// Test Case 7: Price fluctuation - 价格波动测试
// Input: {7, 1, 5, 3, 6, 4}
// Expected Output: 5 (6-1=5)
TEST_F(MaxProfitTest, PriceFluctuation)
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(5, maxProfit(prices));
}

// Test Case 8: Complex price fluctuation - 复杂价格波动测试
// Input: {2, 4, 1, 7, 3, 5}
// Expected Output: 6 (7-1=6)
TEST_F(MaxProfitTest, ComplexFluctuation)
{
    vector<int> prices = {2, 4, 1, 7, 3, 5};
    EXPECT_EQ(6, maxProfit(prices));
}

// Test Case 9: All same prices - 所有价格相同测试
// Input: {3, 3, 3, 3, 3}
// Expected Output: 0
TEST_F(MaxProfitTest, AllSamePrices)
{
    vector<int> prices = {3, 3, 3, 3, 3};
    EXPECT_EQ(0, maxProfit(prices));
}

// Test Case 10: Large price difference - 大价格差异测试
// Input: {1, 1000}
// Expected Output: 999
TEST_F(MaxProfitTest, LargePriceDifference)
{
    vector<int> prices = {1, 1000};
    EXPECT_EQ(999, maxProfit(prices));
}