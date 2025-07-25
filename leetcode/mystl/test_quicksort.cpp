#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "sort.h"
#include <climits>

template <typename T>
void quicksort(std::vector<T> &vec)
{
    my::quicksort(vec);
}

// 测试类模板
template <typename T>
class QuickSortTest : public ::testing::Test
{
protected:
    std::vector<T> test_data;

    // 验证数组是否已排序
    bool is_sorted(const std::vector<T> &vec)
    {
        return std::is_sorted(vec.begin(), vec.end());
    }

    // 生成随机数组
    std::vector<T> generate_random_array(size_t size, T min_val, T max_val)
    {
        std::vector<T> result(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min_val, max_val);

        for (size_t i = 0; i < size; ++i)
        {
            result[i] = static_cast<T>(dis(gen));
        }
        return result;
    }
};

// 使用int类型进行测试
typedef ::testing::Types<int, float, double> TestTypes;
TYPED_TEST_SUITE(QuickSortTest, TestTypes);

// 测试空数组
TYPED_TEST(QuickSortTest, EmptyArray)
{
    std::vector<TypeParam> nums;
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_TRUE(nums.empty());
}

// 测试单元素数组
TYPED_TEST(QuickSortTest, SingleElement)
{
    std::vector<TypeParam> nums = {42};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 1);
    EXPECT_EQ(nums[0], 42);
}

// 测试两元素数组（已排序）
TYPED_TEST(QuickSortTest, TwoElementsSorted)
{
    std::vector<TypeParam> nums = {1, 2};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 2);
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[1], 2);
}

// 测试两元素数组（逆序）
TYPED_TEST(QuickSortTest, TwoElementsReversed)
{
    std::vector<TypeParam> nums = {2, 1};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 2);
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[1], 2);
}

// 测试已排序数组
TYPED_TEST(QuickSortTest, AlreadySorted)
{
    std::vector<TypeParam> nums = {1, 2, 3, 4, 5};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 5);
}

// 测试逆序数组
TYPED_TEST(QuickSortTest, ReverseSorted)
{
    std::vector<TypeParam> nums = {5, 4, 3, 2, 1};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[4], 5);
}

// 测试随机数组
TYPED_TEST(QuickSortTest, RandomArray)
{
    std::vector<TypeParam> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<TypeParam> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums, expected);
}

// 测试包含重复元素的数组
TYPED_TEST(QuickSortTest, DuplicateElements)
{
    std::vector<TypeParam> nums = {3, 1, 3, 1, 3, 1};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 6);
}

// 测试所有元素相同的数组
TYPED_TEST(QuickSortTest, AllSameElements)
{
    std::vector<TypeParam> nums = {5, 5, 5, 5, 5};
    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums.size(), 5);
    for (const auto &elem : nums)
    {
        EXPECT_EQ(elem, 5);
    }
}

// 测试负数数组
TYPED_TEST(QuickSortTest, NegativeNumbers)
{
    std::vector<TypeParam> nums = {-3, -1, -4, -1, -5, -9, -2, -6, -5, -3};
    std::vector<TypeParam> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums, expected);
}

// 测试混合正负数
TYPED_TEST(QuickSortTest, MixedPositiveNegative)
{
    std::vector<TypeParam> nums = {-2, 3, -1, 0, 5, -4, 1};
    std::vector<TypeParam> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums, expected);
}

// 测试大数组性能
TYPED_TEST(QuickSortTest, LargeArray)
{
    auto nums = this->generate_random_array(1000, -1000, 1000);
    std::vector<TypeParam> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(this->is_sorted(nums));
    EXPECT_EQ(nums, expected);
}

// 特定类型测试 - 浮点数精度测试
TEST(QuickSortFloatTest, FloatingPointPrecision)
{
    std::vector<float> nums = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f};
    std::vector<float> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
    EXPECT_EQ(nums, expected);
}

// 特定类型测试 - 双精度浮点数
TEST(QuickSortDoubleTest, DoublePrecision)
{
    std::vector<double> nums = {3.14159, 2.71828, 1.41421, 1.73205, 0.57721};
    std::vector<double> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
    EXPECT_EQ(nums, expected);
}

// 测试稳定性（注意：快速排序不是稳定排序）
TEST(QuickSortStabilityTest, IsNotStable)
{
    // 使用pair来测试稳定性，第一个元素是排序键，第二个是原始索引
    std::vector<std::pair<int, int>> nums = {{3, 0}, {1, 1}, {3, 2}, {2, 3}, {1, 4}};
    quicksort(nums);

    // 验证数组已按第一个元素排序
    EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end(),
                               [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                               {
                                   return a.first < b.first;
                               }));
}

// 边界值测试
TEST(QuickSortBoundaryTest, ExtremeValues)
{
    std::vector<int> nums = {INT_MAX, INT_MIN, 0, -1, 1};
    std::vector<int> expected = nums;
    std::sort(expected.begin(), expected.end());

    quicksort(nums);
    EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
    EXPECT_EQ(nums, expected);
}