/*347. 前 K 个高频元素

https://leetcode.cn/problems/top-k-frequent-elements/description/?envType=study-plan-v2&envId=top-100-liked
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

思路：统计每个元素出现次数，根据出现次数排序，找出出现次数前k的元素。
-   找出前k的元素，可用堆排序。时间复杂度O(nlogn)，空间复杂度O(nlogn)。
-   不关心前k元素的顺序，所以无需完全排序，可以通过快速排序，快速找出。
*/
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int &num : nums)
            freq[num]++;

        vector<pair<int, int>> freqs;
        for (auto &[num, freq] : freq)
            freqs.push_back({freq, num});
        sort(freqs.begin(), freqs.end(), greater<pair<int, int>>());

        vector<int> ans;
        for (int i = 0; i < k && i < freqs.size(); i++)
            ans.push_back(freqs[i].second);

        return ans;
    }

    vector<int> topKFrequent1(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int &num : nums)
            freq[num]++;

        vector<pair<int, int>> freqs;
        for (auto &[num, freq] : freq)
            freqs.push_back({freq, num});

        make_heap(freqs.begin(), freqs.end()); // 默认构建最大堆

        vector<int> ans;
        while (ans.size() < k && freqs.size() > 0)
        {
            pop_heap(freqs.begin(), freqs.end());
            ans.push_back(freqs.back().second);
            freqs.pop_back();
        }

        return ans;
    }
};

// 被测函数
vector<int> topKFrequent(vector<int> &nums, int k)
{
    return Solution().topKFrequent1(nums, k);
}

// Test Fixture for topKFrequent function
class TopKFrequentTest : public ::testing::Test
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
 * Test Case 1: Normal case - Standard input with different frequencies
 * 测试用例1：正常情况 - 不同频率的标准输入
 * Input: [1,1,1,2,2,3], k=2
 * Expected: [1,2] (order may vary)
 */
TEST_F(TopKFrequentTest, NormalCase)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    // 验证结果大小
    EXPECT_EQ(result.size(), 2);

    // 验证结果包含正确的元素（顺序可能不同）
    vector<int> expectedElements = {1, 2};
    for (int elem : expectedElements)
    {
        EXPECT_NE(find(result.begin(), result.end(), elem), result.end());
    }

    // 验证1的频率确实高于2的频率（通过元素顺序间接验证）
    if (result.size() >= 2)
    {
        // 第一个元素应该是频率最高的1
        EXPECT_EQ(result[0], 1);
    }
}

/**
 * Test Case 2: All elements have same frequency
 * 测试用例2：所有元素频率相同
 * Input: [1,2,3], k=2
 * Expected: Any 2 elements from {1,2,3}
 */
TEST_F(TopKFrequentTest, SameFrequency)
{
    vector<int> nums = {1, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_EQ(result.size(), 2);

    // 验证结果中的元素都在原数组中
    for (int elem : result)
    {
        EXPECT_NE(find(nums.begin(), nums.end(), elem), nums.end());
    }

    // 验证没有重复元素
    EXPECT_NE(result[0], result[1]);
}

/**
 * Test Case 3: Single element array
 * 测试用例3：单元素数组
 * Input: [1], k=1
 * Expected: [1]
 */
TEST_F(TopKFrequentTest, SingleElement)
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 1);
}

/**
 * Test Case 4: Empty array
 * 测试用例4：空数组
 * Input: [], k=1
 * Expected: []
 */
TEST_F(TopKFrequentTest, EmptyArray)
{
    vector<int> nums = {};
    int k = 1;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_TRUE(result.empty());
}

/**
 * Test Case 5: k equals to array size
 * 测试用例5：k等于数组大小
 * Input: [1,1,2,2,3,3], k=3
 * Expected: [1,2,3] (all elements)
 */
TEST_F(TopKFrequentTest, KEqualsArraySize)
{
    vector<int> nums = {1, 1, 2, 2, 3, 3};
    int k = 3;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_EQ(result.size(), 3);

    // 验证包含所有唯一元素
    vector<int> expected = {1, 2, 3};
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

/**
 * Test Case 6: k is zero
 * 测试用例6：k为0
 * Input: [1,1,1,2,2,3], k=0
 * Expected: []
 */
TEST_F(TopKFrequentTest, KIsZero)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 0;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_TRUE(result.empty());
}

/**
 * Test Case 7: Large k value
 * 测试用例7：k值过大
 * Input: [1,2], k=5
 * Expected: [1,2] (return all elements)
 */
TEST_F(TopKFrequentTest, LargeKValue)
{
    vector<int> nums = {1, 2};
    int k = 5;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_EQ(result.size(), 2);

    vector<int> expected = {1, 2};
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

/**
 * Test Case 8: Complex frequency distribution
 * 测试用例8：复杂频率分布
 * Input: [1,1,1,2,2,3,4,4,4,4], k=3
 * Expected: [4,1,2] or [4,2,1] (4 appears 4 times, 1 and 2 appear 3 and 2 times respectively)
 */
TEST_F(TopKFrequentTest, ComplexFrequency)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int k = 3;
    vector<int> result = topKFrequent(nums, k);

    EXPECT_EQ(result.size(), 3);

    // 验证包含频率最高的三个元素
    vector<int> expectedTopElements = {1, 2, 4};
    for (int elem : result)
    {
        EXPECT_NE(find(expectedTopElements.begin(), expectedTopElements.end(), elem),
                  expectedTopElements.end());
    }

    // 验证3不在结果中（频率最低）
    EXPECT_EQ(find(result.begin(), result.end(), 3), result.end());
}