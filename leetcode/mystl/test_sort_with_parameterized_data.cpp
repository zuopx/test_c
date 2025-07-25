#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "sort.h"

// Test fixture for parameterized tests
class SortingTest : public ::testing::TestWithParam<std::vector<int>>
{
protected:
    void SetUp() override
    {
        // Prepare input data
        input_data = GetParam();
        // Create expected result by sorting with std::sort
        expected_result = input_data;
        std::sort(expected_result.begin(), expected_result.end());
    }

    std::vector<int> input_data;
    std::vector<int> expected_result;
};

// Test cases for different input scenarios
INSTANTIATE_TEST_SUITE_P(
    SortingTests,
    SortingTest,
    ::testing::Values(
        // Empty array
        std::vector<int>{},
        // Single element
        std::vector<int>{42},
        // Two elements already sorted
        std::vector<int>{1, 2},
        // Two elements reverse sorted
        std::vector<int>{2, 1},
        // Three elements
        std::vector<int>{3, 1, 2},
        // Duplicates
        std::vector<int>{5, 2, 8, 2, 9, 1, 5, 5},
        // Already sorted
        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        // Reverse sorted
        std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        // All same elements
        std::vector<int>{7, 7, 7, 7, 7},
        // Negative numbers
        std::vector<int>{-3, -1, -4, -1, -5, -9, -2, -6},
        // Mixed positive and negative
        std::vector<int>{-3, 1, -4, 1, 5, -9, 2, 6},
        // Large random array
        []
        {
            std::vector<int> large(1000);
            std::mt19937 gen(42); // Fixed seed for reproducibility
            std::uniform_int_distribution<> dis(-1000, 1000);
            for (int &val : large)
            {
                val = dis(gen);
            }
            return large;
        }()));

// Test quicksort implementation
TEST_P(SortingTest, QuickSortTest)
{
    auto test_data = input_data;
    my::quicksort(test_data);
    EXPECT_EQ(test_data, expected_result);
}

// Test insertsort implementation
TEST_P(SortingTest, InsertSortTest)
{
    auto test_data = input_data;
    my::insertsort(test_data);
    EXPECT_EQ(test_data, expected_result);
}

// Test heapsort implementation (will fail until implemented)
TEST_P(SortingTest, HeapSortTest)
{
    auto test_data = input_data;
    my::heapsort(test_data);
    EXPECT_EQ(test_data, expected_result);
}

// Additional test for stability (not applicable for these sorting algorithms since they're not stable)
// But we can test that they still sort correctly with pairs
TEST(SortingStabilityTest, SortPairsByFirstElement)
{
    std::vector<std::pair<int, char>> data = {
        {3, 'a'}, {1, 'b'}, {3, 'c'}, {2, 'd'}, {1, 'e'}};

    std::vector<std::pair<int, char>> expected = {
        {1, 'b'}, {1, 'e'}, {2, 'd'}, {3, 'a'}, {3, 'c'}};

    // Test quicksort
    auto quicksort_data = data;
    my::quicksort(quicksort_data);
    EXPECT_EQ(quicksort_data, expected);

    // Test insertsort
    auto insertsort_data = data;
    my::insertsort(insertsort_data);
    EXPECT_EQ(insertsort_data, expected);

    // Test insertsort
    auto heapsort_data = data;
    my::heapsort(heapsort_data);
    EXPECT_EQ(heapsort_data, expected);
}