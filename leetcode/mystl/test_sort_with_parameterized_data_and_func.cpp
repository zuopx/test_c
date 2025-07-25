#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include "sort.h"

// Test fixture with both data and algorithm as parameters
class SortingAlgorithmTest : public ::testing::TestWithParam<
                                 std::tuple<
                                     std::function<void(std::vector<int> &)>, // Sorting function
                                     std::vector<int>                         // Test data
                                     >>
{
protected:
    void SetUp() override
    {
        auto param = GetParam();
        sort_function = std::get<0>(param);
        input_data = std::get<1>(param);
        expected_result = input_data;
        std::sort(expected_result.begin(), expected_result.end());
    }

    std::function<void(std::vector<int> &)> sort_function;
    std::vector<int> input_data;
    std::vector<int> expected_result;
};

// Test all sorting algorithms with various input data
INSTANTIATE_TEST_SUITE_P(
    AllSortingAlgorithms,
    SortingAlgorithmTest,
    ::testing::Combine(
        // First parameter: sorting algorithms
        ::testing::Values(
            [](std::vector<int> &arr)
            { my::quicksort(arr); },
            [](std::vector<int> &arr)
            { my::insertsort(arr); }),
        // Second parameter: test data
        ::testing::Values(
            // Edge cases
            std::vector<int>{},     // Empty array
            std::vector<int>{42},   // Single element
            std::vector<int>{1, 2}, // Two elements sorted
            std::vector<int>{2, 1}, // Two elements reversed

            // Regular cases
            std::vector<int>{3, 1, 2},                // Small array
            std::vector<int>{5, 2, 8, 2, 9, 1, 5, 5}, // Array with duplicates
            std::vector<int>{1, 2, 3, 4, 5},          // Already sorted
            std::vector<int>{5, 4, 3, 2, 1},          // Reverse sorted
            std::vector<int>{3, 3, 3, 3, 3},          // All same elements
            std::vector<int>{-1, -5, -2, -10, -1},    // Negative numbers

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
            }())));

// Main test for sorting algorithms
TEST_P(SortingAlgorithmTest, SortsCorrectly)
{
    auto test_data = input_data;
    sort_function(test_data);
    EXPECT_EQ(test_data, expected_result);
}
