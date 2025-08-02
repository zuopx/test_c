#include <queue>
#include <gtest/gtest.h>
using namespace std;

class TestPriorityQueue : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(TestPriorityQueue, test_default_comparator)
{
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    EXPECT_EQ(pq.top(), 3);
}

TEST_F(TestPriorityQueue, test_custom_comparator)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    EXPECT_EQ(pq.top(), 1);
}

TEST_F(TestPriorityQueue, test_priority_queue_with_custom_type)
{
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(1, 1));
    pq.push(make_pair(1, 2));
    pq.push(make_pair(2, 2));

    EXPECT_EQ(pq.top(), make_pair(2, 2));
}