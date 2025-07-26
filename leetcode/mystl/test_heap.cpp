#include <gtest/gtest.h>
#include "heap.h"
#include <vector>
#include <algorithm>
#include <random>

// Test fixture for Heap class
template <typename T>
class HeapTest : public ::testing::Test
{
protected:
    my::Heap<T> heap;
};

// Test types
typedef ::testing::Types<int, float, double> TestTypes;

TYPED_TEST_SUITE(HeapTest, TestTypes);

// Test default constructor
TYPED_TEST(HeapTest, DefaultConstructor)
{
    EXPECT_TRUE(this->heap.empty());
    EXPECT_EQ(this->heap.size(), 0);
}

// Test constructor with reversed parameter
TYPED_TEST(HeapTest, ConstructorWithReversed)
{
    my::Heap<TypeParam> min_heap(false); // Min heap
    my::Heap<TypeParam> max_heap(true);  // Max heap

    EXPECT_TRUE(min_heap.empty());
    EXPECT_TRUE(max_heap.empty());
    EXPECT_EQ(min_heap.size(), 0);
    EXPECT_EQ(max_heap.size(), 0);
}

// Test push and top for min heap
TYPED_TEST(HeapTest, PushAndTopMinHeap)
{
    this->heap.push(static_cast<TypeParam>(5));
    this->heap.push(static_cast<TypeParam>(3));
    this->heap.push(static_cast<TypeParam>(8));
    this->heap.push(static_cast<TypeParam>(1));

    EXPECT_EQ(this->heap.top(), static_cast<TypeParam>(1));
    EXPECT_EQ(this->heap.size(), 4);
}

// Test push and top for max heap
TYPED_TEST(HeapTest, PushAndTopMaxHeap)
{
    my::Heap<TypeParam> max_heap(true);
    max_heap.push(static_cast<TypeParam>(5));
    max_heap.push(static_cast<TypeParam>(3));
    max_heap.push(static_cast<TypeParam>(8));
    max_heap.push(static_cast<TypeParam>(1));

    EXPECT_EQ(max_heap.top(), static_cast<TypeParam>(8));
    EXPECT_EQ(max_heap.size(), 4);
}

// Test pop operation
TYPED_TEST(HeapTest, PopMinHeap)
{
    this->heap.push(static_cast<TypeParam>(5));
    this->heap.push(static_cast<TypeParam>(3));
    this->heap.push(static_cast<TypeParam>(8));
    this->heap.push(static_cast<TypeParam>(1));

    EXPECT_EQ(this->heap.top(), static_cast<TypeParam>(1));
    this->heap.pop();
    EXPECT_EQ(this->heap.top(), static_cast<TypeParam>(3));
    this->heap.pop();
    EXPECT_EQ(this->heap.top(), static_cast<TypeParam>(5));
    this->heap.pop();
    EXPECT_EQ(this->heap.top(), static_cast<TypeParam>(8));
    this->heap.pop();
    EXPECT_TRUE(this->heap.empty());
}

// Test pop operation on max heap
TYPED_TEST(HeapTest, PopMaxHeap)
{
    my::Heap<TypeParam> max_heap(true);
    max_heap.push(static_cast<TypeParam>(5));
    max_heap.push(static_cast<TypeParam>(3));
    max_heap.push(static_cast<TypeParam>(8));
    max_heap.push(static_cast<TypeParam>(1));

    EXPECT_EQ(max_heap.top(), static_cast<TypeParam>(8));
    max_heap.pop();
    EXPECT_EQ(max_heap.top(), static_cast<TypeParam>(5));
    max_heap.pop();
    EXPECT_EQ(max_heap.top(), static_cast<TypeParam>(3));
    max_heap.pop();
    EXPECT_EQ(max_heap.top(), static_cast<TypeParam>(1));
    max_heap.pop();
    EXPECT_TRUE(max_heap.empty());
}

// Test pop on empty heap
TYPED_TEST(HeapTest, PopEmptyHeap)
{
    // Should not crash
    this->heap.pop();
    EXPECT_TRUE(this->heap.empty());
}

// Test top on empty heap - this would be undefined behavior, so we won't test it

// Test clear operation
TYPED_TEST(HeapTest, Clear)
{
    this->heap.push(static_cast<TypeParam>(5));
    this->heap.push(static_cast<TypeParam>(3));
    this->heap.push(static_cast<TypeParam>(8));

    EXPECT_EQ(this->heap.size(), 3);
    this->heap.clear();
    EXPECT_TRUE(this->heap.empty());
    EXPECT_EQ(this->heap.size(), 0);
}

// Test with many elements
TYPED_TEST(HeapTest, ManyElements)
{
    std::vector<TypeParam> values;

    // Generate test data
    if constexpr (std::is_integral_v<TypeParam>)
    {
        std::mt19937 gen(42);
        std::uniform_int_distribution<> dis(1, 1000);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }
    else
    {
        std::mt19937 gen(42);
        std::uniform_real_distribution<> dis(1.0, 1000.0);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }

    // Push all values to heap
    for (const auto &val : values)
    {
        this->heap.push(val);
    }

    EXPECT_EQ(this->heap.size(), 100);

    // Pop all values and check they are in sorted order
    std::vector<TypeParam> popped_values;
    while (!this->heap.empty())
    {
        popped_values.push_back(this->heap.top());
        this->heap.pop();
    }

    // Check if values are sorted (min heap)
    EXPECT_TRUE(std::is_sorted(popped_values.begin(), popped_values.end()));
}

// Test with many elements in max heap
TYPED_TEST(HeapTest, ManyElementsMaxHeap)
{
    my::Heap<TypeParam> max_heap(true);
    std::vector<TypeParam> values;

    // Generate test data
    if constexpr (std::is_integral_v<TypeParam>)
    {
        std::mt19937 gen(42);
        std::uniform_int_distribution<> dis(1, 1000);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }
    else
    {
        std::mt19937 gen(42);
        std::uniform_real_distribution<> dis(1.0, 1000.0);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }

    // Push all values to heap
    for (const auto &val : values)
    {
        max_heap.push(val);
    }

    EXPECT_EQ(max_heap.size(), 100);

    // Pop all values and check they are in sorted order (descending)
    std::vector<TypeParam> popped_values;
    while (!max_heap.empty())
    {
        popped_values.push_back(max_heap.top());
        max_heap.pop();
    }

    // Check if values are sorted in descending order (max heap)
    EXPECT_TRUE(std::is_sorted(popped_values.rbegin(), popped_values.rend()));
}

// Test fixture for PriorityQueue class
template <typename T>
class PriorityQueueTest : public ::testing::Test
{
protected:
    my::PriorityQueue<T> pq;
};

TYPED_TEST_SUITE(PriorityQueueTest, TestTypes);

// Test default constructor
TYPED_TEST(PriorityQueueTest, DefaultConstructor)
{
    EXPECT_TRUE(this->pq.empty());
    EXPECT_EQ(this->pq.size(), 0);
}

// Test constructor with reversed parameter
TYPED_TEST(PriorityQueueTest, ConstructorWithReversed)
{
    my::PriorityQueue<TypeParam> min_pq(false); // Min priority queue
    my::PriorityQueue<TypeParam> max_pq(true);  // Max priority queue

    EXPECT_TRUE(min_pq.empty());
    EXPECT_TRUE(max_pq.empty());
    EXPECT_EQ(min_pq.size(), 0);
    EXPECT_EQ(max_pq.size(), 0);
}

// Test put and get for min priority queue
TYPED_TEST(PriorityQueueTest, PutAndGetMinPQ)
{
    this->pq.put(static_cast<TypeParam>(5));
    this->pq.put(static_cast<TypeParam>(3));
    this->pq.put(static_cast<TypeParam>(8));
    this->pq.put(static_cast<TypeParam>(1));

    EXPECT_EQ(this->pq.size(), 4);
    EXPECT_EQ(this->pq.get(), static_cast<TypeParam>(1));
    EXPECT_EQ(this->pq.size(), 3);
    EXPECT_EQ(this->pq.get(), static_cast<TypeParam>(3));
    EXPECT_EQ(this->pq.size(), 2);
    EXPECT_EQ(this->pq.get(), static_cast<TypeParam>(5));
    EXPECT_EQ(this->pq.size(), 1);
    EXPECT_EQ(this->pq.get(), static_cast<TypeParam>(8));
    EXPECT_TRUE(this->pq.empty());
}

// Test put and get for max priority queue
TYPED_TEST(PriorityQueueTest, PutAndGetMaxPQ)
{
    my::PriorityQueue<TypeParam> max_pq(true);
    max_pq.put(static_cast<TypeParam>(5));
    max_pq.put(static_cast<TypeParam>(3));
    max_pq.put(static_cast<TypeParam>(8));
    max_pq.put(static_cast<TypeParam>(1));

    EXPECT_EQ(max_pq.size(), 4);
    EXPECT_EQ(max_pq.get(), static_cast<TypeParam>(8));
    EXPECT_EQ(max_pq.size(), 3);
    EXPECT_EQ(max_pq.get(), static_cast<TypeParam>(5));
    EXPECT_EQ(max_pq.size(), 2);
    EXPECT_EQ(max_pq.get(), static_cast<TypeParam>(3));
    EXPECT_EQ(max_pq.size(), 1);
    EXPECT_EQ(max_pq.get(), static_cast<TypeParam>(1));
    EXPECT_TRUE(max_pq.empty());
}

// Test get on empty priority queue
TYPED_TEST(PriorityQueueTest, GetEmptyPQ)
{
    // Should not crash, but behavior is undefined for get() on empty queue
    // We won't test this as it would be undefined behavior
}

// Test clear operation
TYPED_TEST(PriorityQueueTest, Clear)
{
    this->pq.put(static_cast<TypeParam>(5));
    this->pq.put(static_cast<TypeParam>(3));
    this->pq.put(static_cast<TypeParam>(8));

    EXPECT_EQ(this->pq.size(), 3);
    this->pq.clear();
    EXPECT_TRUE(this->pq.empty());
    EXPECT_EQ(this->pq.size(), 0);
}

// Test with many elements
TYPED_TEST(PriorityQueueTest, ManyElements)
{
    std::vector<TypeParam> values;

    // Generate test data
    if constexpr (std::is_integral_v<TypeParam>)
    {
        std::mt19937 gen(42);
        std::uniform_int_distribution<> dis(1, 1000);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }
    else
    {
        std::mt19937 gen(42);
        std::uniform_real_distribution<> dis(1.0, 1000.0);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }

    // Put all values to priority queue
    for (const auto &val : values)
    {
        this->pq.put(val);
    }

    EXPECT_EQ(this->pq.size(), 100);

    // Get all values and check they are in sorted order
    std::vector<TypeParam> popped_values;
    while (!this->pq.empty())
    {
        popped_values.push_back(this->pq.get());
    }

    // Check if values are sorted (min priority queue)
    EXPECT_TRUE(std::is_sorted(popped_values.begin(), popped_values.end()));
}

// Test with many elements in max priority queue
TYPED_TEST(PriorityQueueTest, ManyElementsMaxPQ)
{
    my::PriorityQueue<TypeParam> max_pq(true);
    std::vector<TypeParam> values;

    // Generate test data
    if constexpr (std::is_integral_v<TypeParam>)
    {
        std::mt19937 gen(42);
        std::uniform_int_distribution<> dis(1, 1000);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }
    else
    {
        std::mt19937 gen(42);
        std::uniform_real_distribution<> dis(1.0, 1000.0);
        for (int i = 0; i < 100; ++i)
        {
            values.push_back(static_cast<TypeParam>(dis(gen)));
        }
    }

    // Put all values to priority queue
    for (const auto &val : values)
    {
        max_pq.put(val);
    }

    EXPECT_EQ(max_pq.size(), 100);

    // Get all values and check they are in sorted order (descending)
    std::vector<TypeParam> popped_values;
    while (!max_pq.empty())
    {
        popped_values.push_back(max_pq.get());
    }

    // Check if values are sorted in descending order (max priority queue)
    EXPECT_TRUE(std::is_sorted(popped_values.rbegin(), popped_values.rend()));
}