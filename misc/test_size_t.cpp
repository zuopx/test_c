#include <vector>
#include <gtest/gtest.h>
using namespace std;

TEST(test_size_t, test_size_t)
{
    vector<int> v1;
    vector<int> v2;
    v2.push_back(1);

    EXPECT_TRUE(v1.size() == 0);
    EXPECT_TRUE(v2.size() == 1);
    EXPECT_TRUE(v1.size() - v2.size() > 1);  // size_t 减法结果可能溢出
}