/*76. 最小覆盖子串

https://leetcode.cn/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-100-liked

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
#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int cnt_s[128] = {0};
        int cnt_t[128] = {0};
        auto check = [&]() -> bool
        {
            for (int i = 0; i < 128; i++)
            {
                if (cnt_s[i] < cnt_t[i])
                {
                    return false;
                }
            }
            return true;
        };

        for (char &c : t)
            cnt_t[c]++;

        int ans_left = -1, ans_right = s.size();
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            cnt_s[s[right]]++;
            while (check())
            {
                if (right - left < ans_right - ans_left)
                {
                    ans_right = right;
                    ans_left = left;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }

        return ans_left == -1 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

string minWindow(string s, string t)
{
    return Solution().minWindow(s, t);
}

// Test Suite: MinWindowTest
class MinWindowTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // 测试前的初始化
    }

    void TearDown() override
    {
        // 测试后的清理
    }
};

// TC001: Basic functionality test - Normal case with valid result
// 测试用例：基本功能测试 - 存在有效结果的正常情况
TEST_F(MinWindowTest, BasicFunctionality)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string expected = "BANC";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC002: Single character match - Single character matching
// 测试用例：单字符匹配 - 单个字符的匹配情况
TEST_F(MinWindowTest, SingleCharacterMatch)
{
    string s = "a";
    string t = "a";
    string expected = "a";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC003: Insufficient characters - t中字符重复但s中数量不足
// 测试用例：字符不足 - t中有重复字符但s中对应字符数量不够
TEST_F(MinWindowTest, InsufficientCharacters)
{
    string s = "a";
    string t = "aa";
    string expected = "";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC004: Empty source string - 源字符串为空
// 测试用例：空源字符串 - s为空字符串的情况
TEST_F(MinWindowTest, EmptySourceString)
{
    string s = "";
    string t = "a";
    string expected = "";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC005: Empty target string - 目标字符串为空
// 测试用例：空目标字符串 - t为空字符串的情况
TEST_F(MinWindowTest, EmptyTargetString)
{
    string s = "a";
    string t = "";
    string expected = "";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC006: No matching characters - 无匹配字符
// 测试用例：无匹配字符 - s和t没有共同字符
TEST_F(MinWindowTest, NoMatchingCharacters)
{
    string s = "abc";
    string t = "def";
    string expected = "";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC007: Partial match - 部分匹配
// 测试用例：部分匹配 - 只匹配部分字符
TEST_F(MinWindowTest, PartialMatch)
{
    string s = "ab";
    string t = "b";
    string expected = "b";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC008: Complex case with repeated characters - 复杂重复字符情况
// 测试用例：复杂重复字符 - 包含多个重复字符的复杂情况
TEST_F(MinWindowTest, ComplexRepeatedCharacters)
{
    string s = "ADOBECODEBANC";
    string t = "ADBC";
    string expected = "ADOBEC";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC009: Target longer than source - 目标字符串长于源字符串
// 测试用例：目标更长 - t的长度大于s的长度
TEST_F(MinWindowTest, TargetLongerThanSource)
{
    string s = "ab";
    string t = "abc";
    string expected = "";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// TC010: Identical strings - 相同字符串
// 测试用例：相同字符串 - s和t完全相同
TEST_F(MinWindowTest, IdenticalStrings)
{
    string s = "abc";
    string t = "abc";
    string expected = "abc";
    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

// 参数化测试 - 测试多种输入组合
// Parameterized test - Test multiple input combinations
class MinWindowParamTest : public ::testing::TestWithParam<std::tuple<string, string, string>>
{
};

// TC011-013: Parameterized test cases - 参数化测试用例
TEST_P(MinWindowParamTest, ParameterizedTest)
{
    auto params = GetParam();
    string s = std::get<0>(params);
    string t = std::get<1>(params);
    string expected = std::get<2>(params);

    string result = minWindow(s, t);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinWindowTests,
    MinWindowParamTest,
    ::testing::Values(
        std::make_tuple("a", "a", "a"), // TC011: Simple match
        std::make_tuple("", "a", ""),   // TC012: Empty source
        std::make_tuple("a", "", "")    // TC013: Empty target
        ));

// 性能测试 - Performance test for large input
// 测试用例：大输入性能测试 - 测试处理大字符串的性能
TEST_F(MinWindowTest, PerformanceTest)
{
    string s(10000, 'a'); // 10000个'a'
    string t = "a";
    string result = minWindow(s, t);
    EXPECT_EQ(result, "a");
}

// 边界值测试 - Boundary value test
// 测试用例：边界值测试 - 测试字符串长度的边界情况
TEST_F(MinWindowTest, BoundaryValueTest)
{
    // 测试最大长度情况
    string s = string(100000, 'a');
    string t = "a";
    string result = minWindow(s, t);
    EXPECT_EQ(result, "a");
}