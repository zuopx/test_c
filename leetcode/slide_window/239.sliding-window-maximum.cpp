/*239. 滑动窗口最大值

https://leetcode.cn/problems/sliding-window-maximum/description/?envType=study-plan-v2&envId=top-100-liked

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

对于这k个数字，首先考虑用堆结构。堆结构以O(logk)时间插入新值、维护最大值。
但是堆只能用O(k)时间复杂度删除一个随机元素。
那么不删元素呢？不属于滑动窗口的元素可能占据最大值。
解决办法：在获取最大值时，如果最大值不属于当前滑动窗口，就跳过。那么就需要记录每个元素的索引。
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow1(vector<int> &nums, int k)
    {
        // 这里是实际的实现，为了测试需要提供一个基础实现
        if (nums.empty() || k <= 0 || k > nums.size())
        {
            return {};
        }

        vector<int> result;
        for (int i = 0; i <= (int)nums.size() - k; i++)
        {
            int max_val = *max_element(nums.begin() + i, nums.begin() + i + k);
            result.push_back(max_val);
        }
        return result;
    }

    vector<int> maxSlidingWindow2(vector<int> &nums, int k)
    {
        vector<int> r;
        if (nums.size() < k)
        {
            return r;
        }

        priority_queue<int> heap;
        for (int i = 0; i < k; ++i)
        {
            heap.push(nums[i]);
        }

        unordered_map<int, int> m;
        for (int i = 0, j = k - 1; j < nums.size(); ++i, ++j)
        {
            if (i)
            {
                if (heap.top() == nums[i - 1])
                {
                    heap.pop();
                }
                else
                {
                    m[nums[i - 1]]++;
                }
                heap.push(nums[j]);
            }

            while (m.find(heap.top()) != m.end())
            {
                m[heap.top()]--;
                if (m[heap.top()] == 0)
                {
                    m.erase(heap.top());
                }
                heap.pop();
            }
            r.push_back(heap.top());
        }

        return r;
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;

        priority_queue<tuple<int, int>> pq;
        for (int i = 0; i < k - 1; ++i)
        {
            pq.push(make_tuple(nums[i], i));
        }
        for (int i = k - 1; i < nums.size(); ++i)
        {
            pq.push(make_tuple(nums[i], i));
            while (get<1>(pq.top()) < i - k + 1)
            {
                pq.pop();
            }
            ans.push_back(get<0>(pq.top()));
        }

        return ans;
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    return Solution().maxSlidingWindow(nums, k);
}

// Test suite for maxSlidingWindow function
class MaxSlidingWindowTest : public ::testing::Test
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

// Test case 1: Normal case with positive numbers
// 测试用例1：正常情况，包含正数
TEST_F(MaxSlidingWindowTest, NormalCase)
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> expected = {3, 3, 5, 5, 6, 7};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 2: Window size equals 1
// 测试用例2：窗口大小为1
TEST_F(MaxSlidingWindowTest, SingleWindowSize)
{
    vector<int> nums = {1, 2, 3};
    int k = 1;
    vector<int> expected = {1, 2, 3};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 3: Window size equals array length
// 测试用例3：窗口大小等于数组长度
TEST_F(MaxSlidingWindowTest, FullArrayWindow)
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    vector<int> expected = {3};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 4: Empty array
// 测试用例4：空数组
TEST_F(MaxSlidingWindowTest, EmptyArray)
{
    vector<int> nums = {};
    int k = 1;
    vector<int> expected = {};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 5: Zero window size
// 测试用例5：窗口大小为0
TEST_F(MaxSlidingWindowTest, ZeroWindowSize)
{
    vector<int> nums = {1, 2, 3};
    int k = 0;
    vector<int> expected = {};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 6: Single element array
// 测试用例6：单元素数组
TEST_F(MaxSlidingWindowTest, SingleElementArray)
{
    vector<int> nums = {5};
    int k = 1;
    vector<int> expected = {5};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 7: Window size larger than array
// 测试用例7：窗口大小大于数组长度
TEST_F(MaxSlidingWindowTest, WindowLargerThanArray)
{
    vector<int> nums = {1, 2};
    int k = 3;
    vector<int> expected = {};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 8: Array with negative numbers
// 测试用例8：包含负数的数组
TEST_F(MaxSlidingWindowTest, NegativeNumbers)
{
    vector<int> nums = {-1, -2, -3, -4};
    int k = 2;
    vector<int> expected = {-1, -2, -3};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 9: Array with duplicate elements
// 测试用例9：包含重复元素的数组
TEST_F(MaxSlidingWindowTest, DuplicateElements)
{
    vector<int> nums = {1, 1, 1, 2, 2};
    int k = 3;
    vector<int> expected = {1, 2, 2};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 10: Large numbers
// 测试用例10：大数值测试
TEST_F(MaxSlidingWindowTest, LargeNumbers)
{
    vector<int> nums = {1000000, 999999, 1000001};
    int k = 2;
    vector<int> expected = {1000000, 1000001};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 11: Decreasing sequence
// 测试用例11：递减序列
TEST_F(MaxSlidingWindowTest, DecreasingSequence)
{
    vector<int> nums = {5, 4, 3, 2, 1};
    int k = 2;
    vector<int> expected = {5, 4, 3, 2};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}

// Test case 12: Increasing sequence
// 测试用例12：递增序列
TEST_F(MaxSlidingWindowTest, IncreasingSequence)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> expected = {2, 3, 4, 5};
    vector<int> result = maxSlidingWindow(nums, k);
    EXPECT_EQ(result, expected);
}