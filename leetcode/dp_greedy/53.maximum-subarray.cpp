/*53. 最大子数组和

https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked
*/
#include <gtest/gtest.h>
#include <limits>
#include <vector>

class Solution
{
public:
    int maxSubArray1(std::vector<int> &nums)
    {
        std::vector<int> v{};
        v.push_back(0);
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
            v.push_back(sum);
        }

        int max = INT32_MIN;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                if (v[j] - v[i] > max)
                {
                    max = v[j] - v[i];
                }
            }
        }

        return max;
    }

    /*
    用sum(i)表示前i个数的和，用min(i)表示sum(0)到sum(i)的最小值
    那么sum(i)-min(i)就是前i个数的「连续子数组的最大和」
    */
    int maxSubArray2(std::vector<int> &nums)
    {
        int ret = INT32_MIN;

        int min = INT32_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            min = std::min(min, sum);
            sum += nums[i];

            ret = std::max(ret, sum - min);
        }

        return ret;
    }

    /*
    我们用f(i)代表以第i个数结尾的「连续子数组的最大和」

    状态转移方程：
    f(i)=max{f(i−1)+nums[i],nums[i]}
    */
    int maxSubArray(std::vector<int> &nums)
    {
        int pre = 0, ans = nums[0];
        for (auto &num : nums)
        {
            pre = std::max(pre + num, num);
            ans = std::max(ans, pre);
        }

        return ans;
    }
};

int maxSubArray(std::vector<int> &nums)
{
    return Solution().maxSubArray2(nums);
}

// Test Suite for maxSubArray function
class MaxSubArrayTest : public ::testing::Test
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

/**
 * @brief 测试基本情况：混合正负数
 * Input: [-2,1,-3,4,-1,2,1,-5,4]
 * Expected Output: 6 (子数组 [4,-1,2,1])
 */
TEST_F(MaxSubArrayTest, MixedPositiveAndNegativeNumbers)
{
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 6);
}

/**
 * @brief 测试全负数情况
 * Input: [-2,-3,-1,-5]
 * Expected Output: -1 (最大的单个负数)
 */
TEST_F(MaxSubArrayTest, AllNegativeNumbers)
{
    std::vector<int> nums = {-2, -3, -1, -5};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, -1);
}

/**
 * @brief 测试全正数情况
 * Input: [1,2,3,4,5]
 * Expected Output: 15 (所有元素之和)
 */
TEST_F(MaxSubArrayTest, AllPositiveNumbers)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 15);
}

/**
 * @brief 测试单个元素
 * Input: [5]
 * Expected Output: 5
 */
TEST_F(MaxSubArrayTest, SingleElement)
{
    std::vector<int> nums = {5};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 5);
}

/**
 * @brief 测试单个负数元素
 * Input: [-3]
 * Expected Output: -3
 */
TEST_F(MaxSubArrayTest, SingleNegativeElement)
{
    std::vector<int> nums = {-3};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, -3);
}

/**
 * @brief 测试包含零的数组
 * Input: [-1, 0, -2]
 * Expected Output: 0
 */
TEST_F(MaxSubArrayTest, ArrayWithZeros)
{
    std::vector<int> nums = {-1, 0, -2};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 0);
}

/**
 * @brief 测试较大的数组
 * Input: [5,4,-1,7,8]
 * Expected Output: 23 (所有元素之和)
 */
TEST_F(MaxSubArrayTest, LargerArray)
{
    std::vector<int> nums = {5, 4, -1, 7, 8};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 23);
}

/**
 * @brief 测试交替正负数
 * Input: [1,-1,1,-1,1]
 * Expected Output: 1
 */
TEST_F(MaxSubArrayTest, AlternatingPositiveNegative)
{
    std::vector<int> nums = {1, -1, 1, -1, 1};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, 1);
}

/**
 * @brief 测试边界情况：最小负数
 * Input: [-100000]
 * Expected Output: -100000
 */
TEST_F(MaxSubArrayTest, MinimumValue)
{
    std::vector<int> nums = {-100000};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, -100000);
}

/**
 * @brief 测试经典例子
 * Input: [-2,-1]
 * Expected Output: -1
 */
TEST_F(MaxSubArrayTest, ClassicExample)
{
    std::vector<int> nums = {-2, -1};
    int result = maxSubArray(nums);
    EXPECT_EQ(result, -1);
}