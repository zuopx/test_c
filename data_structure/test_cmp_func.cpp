/*自定义比较函数*/
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class TestComparisonFunctors : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(TestComparisonFunctors, TestGreater)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    sort(v.begin(), v.end(), greater<int>());
    EXPECT_EQ(3, v[0]);
}

TEST_F(TestComparisonFunctors, TestLess)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    sort(v.begin(), v.end(), less<int>()); // 默认cmp为less
    EXPECT_EQ(1, v[0]);
}
