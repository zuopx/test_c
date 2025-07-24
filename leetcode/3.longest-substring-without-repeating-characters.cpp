/*无重复字符串的最长字串    滑动窗口、哈希表

https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked

暴力解法：获取每一个字符串的子串，并判断是否重复，时间复杂度O(n^3)
进阶解法：滑动窗口，固定左指针，右指针向右移动，判断是否重复，重复则左指针向右移动，直到不重复，直到右指针遍历完字符串，时间复杂度O(n^2)
判定重复优化：创建一个map，记录字符出现的位置，如果map中存在当前字符，且位置大于等于i，则说明重复，i更新为map中当前字符的位置加1，时间复杂度O(n)

滑动窗口解题模板：
    //外层循环扩展右边界，内层循环扩展左边界
    for (int l = 0, r = 0 ; r < n ; r++) {
        //当前考虑的元素
        while (l <= r && check()) {//区间[left,right]不符合题意
            //扩展左边界
        }
        //区间[left,right]符合题意，统计相关信息
    }
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;

        int x = 0, y = 0;
        int i = 0, j = 0;
        while (j < s.size())
        {
            if (m.find(s[j]) != m.end() && m[s[j]] >= i)
            {
                if (j - i > y - x)
                {
                    x = i;
                    y = j;
                }
                i = m[s[j]] + 1;
            }
            m[s[j]] = j;
            ++j;
        }
        if (j - i > y - x)
        {
            x = i;
            y = j;
        }

        return y - x;
    }

    // 滑动窗口模板法，外侧循环控制滑动窗口的右指针，内层循环控制滑动窗口的左指针
    int lengthOfLongestSubstring1(string s)
    {
        int ret = 0;

        unordered_set<char> m;
        for (int l = 0, r = 0; r < s.size(); r++)
        {
            while (l <= r && m.find(s[r]) != m.end())
            {
                m.erase(s[l]);
                l++;
            }
            m.insert(s[r]);

            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};

// gtest测试用例
#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

class SolutionTest : public ::testing::Test //  这是一个绝对作用域（absolute scope）引用，可以避免由于命名冲突而导致的潜在问题。
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Test1)
{
    string s = "abcabcbb";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 3);
}

TEST_F(SolutionTest, Test2)
{
    string s = "bbbbb";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 1);
}

TEST_F(SolutionTest, Test3)
{
    string s = "pwwkew";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 3);
}

TEST_F(SolutionTest, Test4)
{
    string s = " ";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 1);
}

TEST_F(SolutionTest, Test5)
{
    string s = "au";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 2);
}

TEST_F(SolutionTest, Test6)
{
    string s = "dvdf";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 3);
}

TEST_F(SolutionTest, Test7)
{
    string s = "abcdabcdabcd";
    int ret = sol.lengthOfLongestSubstring1(s);
    EXPECT_EQ(ret, 4);
}
