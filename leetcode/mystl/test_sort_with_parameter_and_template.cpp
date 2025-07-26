#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <type_traits>
#include "sort.h"

// Template test fixture for sorting algorithms
template <typename T>
class SortingAlgorithmTest : public ::testing::Test
{
protected:
    void test_sort_function(std::function<void(std::vector<T> &)> sort_function, std::vector<T> input_data)
    {
        std::vector<T> expected_result = input_data;
        std::sort(expected_result.begin(), expected_result.end());

        auto test_data = input_data;
        sort_function(test_data);
        EXPECT_EQ(test_data, expected_result);
    }

    std::vector<std::function<void(std::vector<T> &)>> get_test_algorithms()
    {
        std::vector<std::function<void(std::vector<T> &)>> algorithms = {
            [](std::vector<T> &arr)
            { my::quicksort(arr); },
            [](std::vector<T> &arr)
            { my::insertsort(arr); },
            [](std::vector<T> &arr)
            { my::heapsort(arr); }};

        return algorithms;
    }

    std::vector<std::vector<T>> get_test_cases()
    {
        std::vector<std::vector<T>> test_cases = {
            // Edge cases
            std::vector<T>{},                                     // Empty array
            std::vector<T>{static_cast<T>(42)},                   // Single element
            std::vector<T>{static_cast<T>(1), static_cast<T>(2)}, // Two elements sorted
            std::vector<T>{static_cast<T>(2), static_cast<T>(1)}, // Two elements reversed

            // Regular cases
            std::vector<T>{static_cast<T>(3), static_cast<T>(1), static_cast<T>(2)}, // Small array
            // Array with duplicates
            std::vector<T>{static_cast<T>(5), static_cast<T>(2), static_cast<T>(8),
                           static_cast<T>(2), static_cast<T>(9), static_cast<T>(1),
                           static_cast<T>(5), static_cast<T>(5)},
            std::vector<T>{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
                           static_cast<T>(4), static_cast<T>(5)}, // Already sorted
            std::vector<T>{static_cast<T>(5), static_cast<T>(4), static_cast<T>(3),
                           static_cast<T>(2), static_cast<T>(1)}, // Reverse sorted
            std::vector<T>{static_cast<T>(3), static_cast<T>(3), static_cast<T>(3),
                           static_cast<T>(3), static_cast<T>(3)}, // All same elements
            // Negative numbers
            std::vector<T>{static_cast<T>(-1), static_cast<T>(-5), static_cast<T>(-2),
                           static_cast<T>(-10), static_cast<T>(-1)},
            // Mixed positive and negative
            std::vector<T>{static_cast<T>(-3), static_cast<T>(1), static_cast<T>(-4),
                           static_cast<T>(1), static_cast<T>(5), static_cast<T>(-9),
                           static_cast<T>(2), static_cast<T>(6)}};

        // Test large random array
        std::vector<T> large(1000);
        std::mt19937 gen(42); // Fixed seed for reproducibility

        if constexpr (std::is_integral_v<T>)
        {
            std::uniform_int_distribution<> dis(-1000, 1000);
            for (T &val : large)
            {
                val = static_cast<T>(dis(gen));
            }
        }
        else
        {
            std::uniform_real_distribution<> dis(-1000.0, 1000.0);
            for (T &val : large)
            {
                val = static_cast<T>(dis(gen));
            }
        }
        test_cases.push_back(large);

        return test_cases;
    }
};

// // Define the types to be tested
typedef ::testing::Types<int, float, double> MyTypes;
TYPED_TEST_SUITE(SortingAlgorithmTest, MyTypes);

// Main test for sorting algorithms
TYPED_TEST(SortingAlgorithmTest, SortsCorrectly)
{
    std::vector<std::function<void(std::vector<TypeParam> &)>> algorithms = this->get_test_algorithms();

    std::vector<std::vector<TypeParam>> test_cases = this->get_test_cases();

    // Test all algorithms with all test cases
    for (auto &algorithm : algorithms)
    {
        for (auto &test_case : test_cases)
        {
            this->test_sort_function(algorithm, test_case);
        }
    }
}