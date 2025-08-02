/*移动零

https://leetcode.cn/problems/move-zeroes/?envType=study-plan-v2&envId=top-100-liked

给定一个数组 nums，编写一个函数将所有 0
移动到数组的末尾，同时保持非零元素的相对顺序。 请注意，必须在不复制数组的情况下原地对数组进行操作。

滑动窗口解题模板：
    //外层循环扩展右边界，内层循环扩展左边界
    for (int l = 0, r = 0 ; r < n ; r++) {
        //当前考虑的元素
        while (l <= r && check()) {//区间[left,right]不符合题意
            //扩展左边界
        }
        //区间[left,right]符合题意，统计相关信息
    }
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    void moveZeroes1(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i + k < nums.size(); i++)
        {

            if (!nums[i])
            {
                int c = i;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (!nums[j])
                    {
                        continue;
                    }
                    nums[c] = nums[j];
                    nums[j] = 0;
                    c = j;
                }
                k++;
            }
        }
    }

    void moveZeroes2(vector<int> &nums)
    {
        int i = 0, j = 0;

        for (; j < nums.size(); j++)
        {
            if (!nums[j])
            {
                continue;
            }
            else if (i != j)
            {
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
            else
            {
                i++;
            }
        }
    }

    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            while (i < j && nums[i] != 0)
            {
                i++;
            }
            swap(nums[i], nums[j]);
        }
    }
};

// 被测函数
void moveZeroes(vector<int> &nums)
{
    return Solution().moveZeroes(nums);
}

// Helper function to check if array has correct zero movement
bool isValidZeroMovement(const vector<int> &original, const vector<int> &result)
{
    // Check 1: Length should be the same
    if (original.size() != result.size())
        return false;

    // Check 2: Count of each element should be the same
    vector<int> orig_sorted = original;
    vector<int> result_sorted = result;
    sort(orig_sorted.begin(), orig_sorted.end());
    sort(result_sorted.begin(), result_sorted.end());
    if (orig_sorted != result_sorted)
        return false;

    // Check 3: Non-zero elements should maintain relative order
    vector<int> orig_nonzero, result_nonzero;
    for (int num : original)
    {
        if (num != 0)
            orig_nonzero.push_back(num);
    }
    for (int num : result)
    {
        if (num != 0)
            result_nonzero.push_back(num);
    }
    return orig_nonzero == result_nonzero;
}

// Test case 1: Normal array with mixed zeros and non-zeros
// 测试用例1：包含零和非零元素的普通数组
TEST(MoveZeroesTest, NormalArray)
{
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> expected = {1, 3, 12, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 2: Array with all zeros
// 测试用例2：所有元素都是零的数组
TEST(MoveZeroesTest, AllZeros)
{
    vector<int> nums = {0, 0, 0, 0};
    vector<int> expected = {0, 0, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 3: Array with no zeros
// 测试用例3：没有零元素的数组
TEST(MoveZeroesTest, NoZeros)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> expected = {1, 2, 3, 4};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 4: Empty array
// 测试用例4：空数组
TEST(MoveZeroesTest, EmptyArray)
{
    vector<int> nums = {};
    vector<int> expected = {};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 5: Single element array (zero)
// 测试用例5：只有一个零元素的数组
TEST(MoveZeroesTest, SingleZero)
{
    vector<int> nums = {0};
    vector<int> expected = {0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 6: Single element array (non-zero)
// 测试用例6：只有一个非零元素的数组
TEST(MoveZeroesTest, SingleNonZero)
{
    vector<int> nums = {1};
    vector<int> expected = {1};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 7: Zeros at the beginning
// 测试用例7：所有零在开头的数组
TEST(MoveZeroesTest, ZerosAtBeginning)
{
    vector<int> nums = {0, 0, 1, 2, 3};
    vector<int> expected = {1, 2, 3, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 8: Zeros at the end
// 测试用例8：所有零在末尾的数组
TEST(MoveZeroesTest, ZerosAtEnd)
{
    vector<int> nums = {1, 2, 3, 0, 0};
    vector<int> expected = {1, 2, 3, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 9: Alternating zeros and non-zeros
// 测试用例9：交替出现零和非零的数组
TEST(MoveZeroesTest, Alternating)
{
    vector<int> nums = {1, 0, 2, 0, 3, 0};
    vector<int> expected = {1, 2, 3, 0, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 10: Large array
// 测试用例10：大量元素的数组
TEST(MoveZeroesTest, LargeArray)
{
    vector<int> nums(1000, 0);
    for (int i = 0; i < 500; i++)
    {
        nums[i] = i + 1;
    }
    moveZeroes(nums);

    // Check that non-zero elements are in order at the beginning
    for (int i = 0; i < 500; i++)
    {
        EXPECT_EQ(nums[i], i + 1);
    }
    // Check that remaining elements are zeros
    for (int i = 500; i < 1000; i++)
    {
        EXPECT_EQ(nums[i], 0);
    }
}

// Test case 11: Only one zero in large array
// 测试用例11：大量元素中只有一个零的数组
TEST(MoveZeroesTest, OneZeroInLargeArray)
{
    vector<int> nums = {1, 2, 3, 0, 4, 5, 6};
    vector<int> expected = {1, 2, 3, 4, 5, 6, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// Test case 12: Validate zero movement correctness
// 测试用例12：验证零移动的正确性
TEST(MoveZeroesTest, ValidateZeroMovement)
{
    vector<int> original = {0, 1, 0, 3, 12};
    vector<int> result = original;
    moveZeroes(result);

    EXPECT_TRUE(isValidZeroMovement(original, result));
    // Also check specific expected result
    vector<int> expected = {1, 3, 12, 0, 0};
    EXPECT_EQ(result, expected);
}

// Test case 13: Negative numbers
// 测试用例13：包含负数的数组
TEST(MoveZeroesTest, NegativeNumbers)
{
    vector<int> nums = {-1, 0, -2, 0, 3, 0, -4};
    vector<int> expected = {-1, -2, 3, -4, 0, 0, 0};
    moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}