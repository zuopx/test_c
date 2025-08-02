#include <gtest/gtest.h>
using namespace std;

class TestPair : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestPair, test_pair)
{
    pair<int, int> p;
    p = make_pair(1, 2);

    EXPECT_EQ(1, p.first);
    EXPECT_EQ(2, p.second);
}

TEST_F(TestPair, test_tuple)
{
    tuple<int, int> t;
    t = make_tuple(1, 2);

    EXPECT_EQ(1, get<0>(t));
    EXPECT_EQ(2, get<1>(t));
}

TEST_F(TestPair, test_tie)
{
    tuple<int, int> t = make_tuple(1, 2);
    auto [a, b] = t;

    EXPECT_EQ(1, a);
    EXPECT_EQ(2, b);
}