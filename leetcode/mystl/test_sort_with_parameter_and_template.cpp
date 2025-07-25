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

    std::vector<std::vector<T>> get_test_cases();
};

// Specialize for int
template <>
std::vector<std::vector<int>> SortingAlgorithmTest<int>::get_test_cases()
{
    std::vector<std::vector<int>> test_cases = {
        // Edge cases
        std::vector<int>{},     // Empty array
        std::vector<int>{42},   // Single element
        std::vector<int>{1, 2}, // Two elements sorted
        std::vector<int>{2, 1}, // Two elements reversed

        // Regular cases
        std::vector<int>{3, 1, 2},                  // Small array
        std::vector<int>{5, 2, 8, 2, 9, 1, 5, 5},   // Array with duplicates
        std::vector<int>{1, 2, 3, 4, 5},            // Already sorted
        std::vector<int>{5, 4, 3, 2, 1},            // Reverse sorted
        std::vector<int>{3, 3, 3, 3, 3},            // All same elements
        std::vector<int>{-1, -5, -2, -10, -1},      // Negative numbers
        std::vector<int>{-3, 1, -4, 1, 5, -9, 2, 6} // Mixed positive and negative
    };

    // Test large random array
    std::vector<int> large(1000);
    std::mt19937 gen(42); // Fixed seed for reproducibility
    std::uniform_int_distribution<> dis(-1000, 1000);
    for (int &val : large)
    {
        val = dis(gen);
    }
    test_cases.push_back(large);

    return test_cases;
}

// Specialize for float
template <>
std::vector<std::vector<float>> SortingAlgorithmTest<float>::get_test_cases()
{
    std::vector<std::vector<float>> test_cases = {
        // Edge cases
        std::vector<float>{},           // Empty array
        std::vector<float>{42.0f},      // Single element
        std::vector<float>{1.0f, 2.0f}, // Two elements sorted
        std::vector<float>{2.0f, 1.0f}, // Two elements reversed

        // Regular cases
        std::vector<float>{3.0f, 1.0f, 2.0f},                                 // Small array
        std::vector<float>{5.0f, 2.0f, 8.0f, 2.0f, 9.0f, 1.0f, 5.0f, 5.0f},   // Array with duplicates
        std::vector<float>{1.0f, 2.0f, 3.0f, 4.0f, 5.0f},                     // Already sorted
        std::vector<float>{5.0f, 4.0f, 3.0f, 2.0f, 1.0f},                     // Reverse sorted
        std::vector<float>{3.0f, 3.0f, 3.0f, 3.0f, 3.0f},                     // All same elements
        std::vector<float>{-1.5f, -5.2f, -2.1f, -10.8f, -1.0f},               // Negative numbers
        std::vector<float>{-3.3f, 1.1f, -4.4f, 1.5f, 5.9f, -9.2f, 2.6f, 6.7f} // Mixed positive and negative
    };

    // Test large random array
    std::vector<float> large(1000);
    std::mt19937 gen(42); // Fixed seed for reproducibility
    std::uniform_real_distribution<> dis(-1000.0, 1000.0);
    for (float &val : large)
    {
        val = dis(gen);
    }
    test_cases.push_back(large);

    return test_cases;
}

// Specialize for double
template <>
std::vector<std::vector<double>> SortingAlgorithmTest<double>::get_test_cases()
{
    std::vector<std::vector<double>> test_cases = {
        // Edge cases
        std::vector<double>{},         // Empty array
        std::vector<double>{42.0},     // Single element
        std::vector<double>{1.0, 2.0}, // Two elements sorted
        std::vector<double>{2.0, 1.0}, // Two elements reversed

        // Regular cases
        std::vector<double>{3.0, 1.0, 2.0},                            // Small array
        std::vector<double>{5.0, 2.0, 8.0, 2.0, 9.0, 1.0, 5.0, 5.0},   // Array with duplicates
        std::vector<double>{1.0, 2.0, 3.0, 4.0, 5.0},                  // Already sorted
        std::vector<double>{5.0, 4.0, 3.0, 2.0, 1.0},                  // Reverse sorted
        std::vector<double>{3.0, 3.0, 3.0, 3.0, 3.0},                  // All same elements
        std::vector<double>{-1.5, -5.2, -2.1, -10.8, -1.0},            // Negative numbers
        std::vector<double>{-3.3, 1.1, -4.4, 1.5, 5.9, -9.2, 2.6, 6.7} // Mixed positive and negative
    };

    // Test large random array
    std::vector<double> large(1000);
    std::mt19937 gen(42); // Fixed seed for reproducibility
    std::uniform_real_distribution<> dis(-1000.0, 1000.0);
    for (double &val : large)
    {
        val = dis(gen);
    }
    test_cases.push_back(large);

    return test_cases;
}

// Define the types to be tested
typedef ::testing::Types<int, float, double> MyTypes;
TYPED_TEST_SUITE(SortingAlgorithmTest, MyTypes);

// Main test for sorting algorithms
TYPED_TEST(SortingAlgorithmTest, SortsCorrectly)
{
    std::vector<std::function<void(std::vector<TypeParam> &)>> algorithms = {
        [](std::vector<TypeParam> &arr)
        { my::quicksort(arr); },
        [](std::vector<TypeParam> &arr)
        { my::insertsort(arr); },
        [](std::vector<TypeParam> &arr)
        { my::heapsort(arr); }};

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