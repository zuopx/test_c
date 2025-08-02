/*最长连续序列

https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked

给定一个未排序的整数数组 nums
，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

思路：
-   限制了时间复杂度，大概率要用空间换时间
-   空间换时间，基本上是指使用合适的数据结构
-   数据结构，用于组织数据，更高效地读写
*/
#include <gtest/gtest.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto &num : nums)
            s.insert(num);

        int r = 0, a = 0;
        for (auto num : s)
        {
            if (s.count(num - 1))
                continue;

            a = 1;
            while (s.count(num + 1))
            {
                a++;
                num++;
            }

            r = max(r, a);
        }

        return r;
    }
};

int longestConsecutive(vector<int> &nums)
{
    return Solution().longestConsecutive(nums);
}

// Test fixture for longestConsecutive function
class LongestConsecutiveTest : public ::testing::Test
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
TEST_F(LongestConsecutiveTest, EmptyArrayReturnsZero)
{
    vector<int> nums = {};
    EXPECT_EQ(0, longestConsecutive(nums));
}

// Test case 2: Single element array should return 1
// 测试用例2：单元素数组应返回1
TEST_F(LongestConsecutiveTest, SingleElementReturnsOne)
{
    vector<int> nums = {5};
    EXPECT_EQ(1, longestConsecutive(nums));
}

// Test case 3: Already sorted consecutive sequence
// 测试用例3：已排序的连续序列
TEST_F(LongestConsecutiveTest, SortedConsecutiveSequence)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(5, longestConsecutive(nums));
}

// Test case 4: Unsorted consecutive sequence
// 测试用例4：未排序的连续序列
TEST_F(LongestConsecutiveTest, UnsortedConsecutiveSequence)
{
    vector<int> nums = {4, 1, 3, 2};
    EXPECT_EQ(4, longestConsecutive(nums));
}

// Test case 5: Array with duplicate elements
// 测试用例5：包含重复元素的数组
TEST_F(LongestConsecutiveTest, ArrayWithDuplicates)
{
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
    EXPECT_EQ(5, longestConsecutive(nums));
}

// Test case 6: No consecutive elements
// 测试用例6：无连续元素
TEST_F(LongestConsecutiveTest, NoConsecutiveElements)
{
    vector<int> nums = {1, 3, 5, 7, 9};
    EXPECT_EQ(1, longestConsecutive(nums));
}

// Test case 7: Array with negative numbers
// 测试用例7：包含负数的数组
TEST_F(LongestConsecutiveTest, ArrayWithNegativeNumbers)
{
    vector<int> nums = {-2, -1, 0, 1, 2};
    EXPECT_EQ(5, longestConsecutive(nums));
}

// Test case 8: Complex unsorted array with multiple sequences
// 测试用例8：复杂的未排序数组，包含多个序列
TEST_F(LongestConsecutiveTest, ComplexUnsortedArray)
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(4, longestConsecutive(nums)); // Sequence: 1,2,3,4
}

// Test case 9: Large numbers
// 测试用例9：大数值
TEST_F(LongestConsecutiveTest, LargeNumbers)
{
    vector<int> nums = {1000000, 1000001, 1000002};
    EXPECT_EQ(3, longestConsecutive(nums));
}

// Test case 10: Mixed positive and negative with zero
// 测试用例10：正负数混合包含零
TEST_F(LongestConsecutiveTest, MixedPositiveNegativeWithZero)
{
    vector<int> nums = {-1, 0, 1, 10, 11, 12};
    EXPECT_EQ(3, longestConsecutive(nums)); // Sequence: -1,0,1 or 10,11,12
}

// Test case 11: All same elements
// 测试用例11：所有元素相同
TEST_F(LongestConsecutiveTest, AllSameElements)
{
    vector<int> nums = {5, 5, 5, 5};
    EXPECT_EQ(1, longestConsecutive(nums));
}

// Test case 12: Two separate consecutive sequences
// 测试用例12：两个独立的连续序列
TEST_F(LongestConsecutiveTest, TwoSeparateSequences)
{
    vector<int> nums = {1, 2, 3, 10, 11, 12, 13};
    EXPECT_EQ(4, longestConsecutive(nums)); // Longer sequence: 10,11,12,13
}

// Parameterized test for multiple scenarios
// 参数化测试：多种场景
class LongestConsecutiveParamTest : public ::testing::TestWithParam<std::pair<std::vector<int>, int>>
{
};

TEST_P(LongestConsecutiveParamTest, VariousInputs)
{
    auto test_data = GetParam();
    vector<int> input = test_data.first;
    int expected = test_data.second;
    EXPECT_EQ(expected, longestConsecutive(input));
}

INSTANTIATE_TEST_SUITE_P(
    VariousCases,
    LongestConsecutiveParamTest,
    ::testing::Values(
        std::make_pair(std::vector<int>{}, 0),
        std::make_pair(std::vector<int>{1}, 1),
        std::make_pair(std::vector<int>{1, 2, 3}, 3),
        std::make_pair(std::vector<int>{3, 1, 2}, 3),
        std::make_pair(std::vector<int>{1, 3, 5}, 1),
        std::make_pair(std::vector<int>{-3, -2, -1, 0}, 4)));

// Performance test with large input
// 性能测试：大数据量输入
TEST_F(LongestConsecutiveTest, PerformanceTest)
{
    vector<int> nums;
    // Create a large consecutive sequence
    for (int i = 0; i < 10000; ++i)
    {
        nums.push_back(i);
    }
    // Shuffle the array to make it unsorted
    std::random_shuffle(nums.begin(), nums.end());

    EXPECT_EQ(10000, longestConsecutive(nums));
}