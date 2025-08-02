/*41. 缺失的第一个正数

https://leetcode.cn/problems/first-missing-positive/description/?envType=study-plan-v2&envId=top-100-liked

最朴素的方法，排序，然后看0以上哪个整数首先缺失，时间复杂度O(nlogn)
其次，遍历一遍，建立一个哈希表，然后看0以上哪个整数首先缺失，时间复杂度O(n)，空间复杂度O(n)

假设10个正整数，那么范围为1-11
填入a，如果a大于11，则范围为1-10，把所有大于11的数都排除掉，假设还剩下8个数，
重复以上步骤，直到找到缺失的数

假设10个正整数，那么范围为1-11
那么我们尝试把1-11的数都填入数组中，然后从1开始遍历，如果当前数没有被填入，则返回当前数

原地哈希，利用数组来做哈希表，数组的索引就是天然的键，数组的值就是对应的值，这样就可以省去存储空间了
*/

#include <gtest/gtest.h>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            while (nums[i] != i + 1)
            {
                if (nums[i] <= 0 || nums[i] > size || nums[i] == nums[nums[i] - 1])
                    break;

                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int firstMissingPositive(std::vector<int> &nums)
{
    return Solution().firstMissingPositive(nums);
}

// 测试用例：空数组
TEST(FirstMissingPositiveTest, EmptyArray)
{
    std::vector<int> nums = {};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 1);
}

// 测试用例：全负数数组
TEST(FirstMissingPositiveTest, AllNegativeNumbers)
{
    std::vector<int> nums = {-1, -2, -3};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 1);
}

// 测试用例：连续正整数从1开始
TEST(FirstMissingPositiveTest, ConsecutivePositiveFromOne)
{
    std::vector<int> nums = {1, 2, 3};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 4);
}

// 测试用例：缺失第一个正整数
TEST(FirstMissingPositiveTest, MissingFirstPositive)
{
    std::vector<int> nums = {2, 3, 4};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 1);
}

// 测试用例：中间缺失正整数
TEST(FirstMissingPositiveTest, MissingMiddlePositive)
{
    std::vector<int> nums = {1, 3, 4};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 2);
}

// 测试用例：包含重复元素
TEST(FirstMissingPositiveTest, WithDuplicateElements)
{
    std::vector<int> nums = {1, 1, 2};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 3);
}

// 测试用例：包含0和负数
TEST(FirstMissingPositiveTest, WithZeroAndNegative)
{
    std::vector<int> nums = {0, -1, 1, 2};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 3);
}

// 测试用例：大数值数组
TEST(FirstMissingPositiveTest, LargeNumbers)
{
    std::vector<int> nums = {7, 8, 9, 11, 12};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 1);
}

// 测试用例：单个元素为1
TEST(FirstMissingPositiveTest, SingleElementOne)
{
    std::vector<int> nums = {1};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 2);
}

// 测试用例：单个元素不为1
TEST(FirstMissingPositiveTest, SingleElementNotOne)
{
    std::vector<int> nums = {2};
    int result = firstMissingPositive(nums);
    EXPECT_EQ(result, 1);
}