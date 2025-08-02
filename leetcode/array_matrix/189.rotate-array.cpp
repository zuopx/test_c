/*189. 轮转数组

https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-

建立新旧下标的映射关系，然后进行轮转：new = (old + k) % size
*/
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty())
            return;

        int size = nums.size();

        int start = 0;
        int curr = start;
        int curr_val = nums[curr];
        int next, next_val;

        int cnt = 0;
        while (cnt < size)
        {
            next = (curr + k) % size;
            next_val = nums[next];

            nums[next] = curr_val;

            curr = next;
            curr_val = next_val;

            if (curr == start)  // 如果size是k的整数倍，会提前使该等式成立
            {
                start++;
                curr = start;
                curr_val = nums[curr];
            }

            cnt++;
        }
    }
};

void rotate(vector<int> &nums, int k)
{
    return Solution().rotate(nums, k);
}

// 测试套件定义
class RotateTest : public ::testing::Test
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

// TC001: 基本旋转功能测试
// Test basic rotation functionality
TEST_F(RotateTest, BasicRotation)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    vector<int> expected = {5, 6, 7, 1, 2, 3, 4};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "数组应该向右旋转3位";
    // The array should be rotated right by 3 positions
}

// TC002: 包含负数的旋转测试
// Test rotation with negative numbers
TEST_F(RotateTest, RotationWithNegativeNumbers)
{
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    vector<int> expected = {3, 99, -1, -100};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "包含负数的数组应该正确旋转";
    // Array with negative numbers should rotate correctly
}

// TC003: 零旋转测试
// Test zero rotation
TEST_F(RotateTest, ZeroRotation)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 0;
    vector<int> expected = {1, 2, 3, 4, 5, 6};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "k=0时数组应该保持不变";
    // Array should remain unchanged when k=0
}

// TC004: 单元素数组测试
// Test single element array
TEST_F(RotateTest, SingleElementArray)
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> expected = {1};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "单元素数组旋转后应该保持不变";
    // Single element array should remain unchanged after rotation
}

// TC005: 空数组测试
// Test empty array
TEST_F(RotateTest, EmptyArray)
{
    vector<int> nums = {};
    int k = 3;
    vector<int> expected = {};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "空数组旋转后应该仍然为空";
    // Empty array should remain empty after rotation
}

// TC006: k大于数组长度的测试
// Test when k is greater than array size
TEST_F(RotateTest, KGreaterThanArraySize)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 7; // 7 % 5 = 2
    vector<int> expected = {4, 5, 1, 2, 3};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "当k大于数组长度时应该取模运算";
    // When k is greater than array size, it should use modulo operation
}

// TC007: k比数组长度大1的测试
// Test when k is one more than array size
TEST_F(RotateTest, KOneMoreThanArraySize)
{
    vector<int> nums = {1, 2};
    int k = 3; // 3 % 2 = 1
    vector<int> expected = {2, 1};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "k比数组长度大1时应该等效于旋转1位";
    // When k is one more than array size, it should be equivalent to rotating by 1
}

// TC008: k等于数组长度的测试
// Test when k equals array size
TEST_F(RotateTest, KEqualsArraySize)
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 4; // 4 % 4 = 0
    vector<int> expected = {1, 2, 3, 4};

    rotate(nums, k);

    EXPECT_EQ(nums, expected) << "当k等于数组长度时数组应该保持不变";
    // When k equals array size, array should remain unchanged
}