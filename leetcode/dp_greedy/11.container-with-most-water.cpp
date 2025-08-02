/*11. 盛最多水的容器

https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked

正确性证明：缩减搜索空间
https://leetcode.cn/problems/container-with-most-water/solutions/94102/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/?envType=study-plan-v2&envId=top-100-liked
*/
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int r = 0;
        while (i < j)
        {
            r = max(r, min(height[i], height[j]) * (j - i));

            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return r;
    }
};

// 被测函数
int maxArea(vector<int> &height)
{
    return Solution().maxArea(height);
}

// 测试用例
TEST(MaxAreaTest, StandardCase)
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(maxArea(heights), 49);
}

TEST(MaxAreaTest, MinimalCase)
{
    vector<int> heights = {1, 1};
    EXPECT_EQ(maxArea(heights), 1);
}

TEST(MaxAreaTest, EmptyInput)
{
    vector<int> heights = {};
    EXPECT_EQ(maxArea(heights), 0);
}

TEST(MaxAreaTest, SingleElement)
{
    vector<int> heights = {1};
    EXPECT_EQ(maxArea(heights), 0);
}

TEST(MaxAreaTest, SameHeights)
{
    vector<int> heights = {4, 3, 2, 1, 4};
    EXPECT_EQ(maxArea(heights), 16);
}

TEST(MaxAreaTest, MiddleHigher)
{
    vector<int> heights = {1, 2, 1};
    EXPECT_EQ(maxArea(heights), 2);
}

TEST(MaxAreaTest, ComplexCase)
{
    vector<int> heights = {2, 3, 4, 5, 18, 17, 6};
    EXPECT_EQ(maxArea(heights), 17);
}
