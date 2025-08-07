/*763. 划分字母区间

https://leetcode.cn/problems/partition-labels/description/?envType=study-plan-v2&envId=top-100-liked
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。

假设对于字符c，在字符串s中最早出现的索引是i，最晚出现的索引是j。
那么s[i:j+1]是一个包含字符c的所有索引的最小子串，称之为substring(c)。
找出所有substring，然后合并区间重叠的。
*/
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        if (s.empty())
            return {};

        unordered_map<char, pair<int, int>> intervals;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (intervals.find(c) == intervals.end())
            {
                intervals[c] = make_pair(i, i);
            }
            else
            {
                intervals[c].second = i;
            }
        }

        vector<int> res;

        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (intervals[c].first > right)
            {
                res.push_back(right - left + 1);
                left = intervals[c].first;
                right = intervals[c].second;
            }
            else
            {
                right = max(right, intervals[c].second);
            }
        }

        res.push_back(right - left + 1);

        return res;
    }

    // 优化版本
    vector<int> partitionLabels2(string s)
    {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

// 被测函数包装
vector<int> partitionLabels(string s)
{
    return Solution().partitionLabels2(s);
}

// Test Suite: PartitionLabelsTest
class PartitionLabelsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // 测试前的设置
    }

    void TearDown() override
    {
        // 测试后的清理
    }
};

// TC001: Basic functionality test - normal partition case
// 测试基本功能：正常分割情况
TEST_F(PartitionLabelsTest, BasicPartition)
{
    string input = "ababcbacadefegdehijhklij";
    vector<int> expected = {9, 7, 8};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);

    // 验证分割的正确性
    int pos = 0;
    string part1 = input.substr(pos, expected[0]); // "ababcbaca"
    pos += expected[0];
    string part2 = input.substr(pos, expected[1]); // "defegde"
    pos += expected[1];
    string part3 = input.substr(pos, expected[2]); // "hijhklij"

    // 确保各部分之间没有字符重叠
    set<char> chars1(part1.begin(), part1.end());
    set<char> chars2(part2.begin(), part2.end());
    set<char> chars3(part3.begin(), part3.end());

    {
        set<char> intersection;
        set_intersection(chars1.begin(), chars1.end(),
                         chars2.begin(), chars2.end(),
                         inserter(intersection, intersection.begin()));
        EXPECT_TRUE(intersection.empty());
    }
    {
        set<char> intersection;
        set_intersection(chars1.begin(), chars1.end(),
                         chars3.begin(), chars3.end(),
                         inserter(intersection, intersection.begin()));
        EXPECT_TRUE(intersection.empty());
    }
    {
        set<char> intersection;
        set_intersection(chars2.begin(), chars2.end(),
                         chars3.begin(), chars3.end(),
                         inserter(intersection, intersection.begin()));
        EXPECT_TRUE(intersection.empty());
    }
}

// TC002: Edge case - single character
// 测试边界情况：单个字符
TEST_F(PartitionLabelsTest, SingleCharacter)
{
    string input = "a";
    vector<int> expected = {1};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC003: Edge case - all same characters
// 测试特殊情况：所有字符相同
TEST_F(PartitionLabelsTest, AllSameCharacters)
{
    string input = "aaaa";
    vector<int> expected = {4};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC004: Edge case - all different characters
// 测试特殊情况：所有字符不同
TEST_F(PartitionLabelsTest, AllDifferentCharacters)
{
    string input = "abcdef";
    vector<int> expected = {1, 1, 1, 1, 1, 1};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC005: Complex case - all characters overlap
// 测试复杂情况：所有字符重叠
TEST_F(PartitionLabelsTest, AllCharactersOverlap)
{
    string input = "eccbbbbdec";
    vector<int> expected = {10};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC006: Edge case - empty string
// 测试边界情况：空字符串
TEST_F(PartitionLabelsTest, EmptyString)
{
    string input = "";
    vector<int> expected = {};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC007: Performance test - maximum length
// 性能测试：最大长度字符串
TEST_F(PartitionLabelsTest, MaxLengthString)
{
    string input(500, 'a'); // 500个相同字符
    vector<int> expected = {500};
    vector<int> result = partitionLabels(input);

    EXPECT_EQ(result, expected);
}

// TC008: Validation test - verify partition correctness
// 验证测试：确保分割结果正确
TEST_F(PartitionLabelsTest, VerifyPartitionCorrectness)
{
    string input = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(input);

    // 验证长度总和等于原字符串长度
    int total_length = 0;
    for (int len : result)
    {
        total_length += len;
    }
    EXPECT_EQ(total_length, input.length());

    // 验证每个片段长度为正数
    for (int len : result)
    {
        EXPECT_GT(len, 0);
    }

    // 验证分割点的正确性
    int pos = 0;
    for (int len : result)
    {
        string partition = input.substr(pos, len);
        set<char> chars(partition.begin(), partition.end());

        // 检查该片段中的每个字符是否都只在这个片段中出现
        for (char c : chars)
        {
            size_t first_pos = input.find(c);
            size_t last_pos = input.rfind(c);

            EXPECT_GE(first_pos, pos);
            EXPECT_LT(last_pos, pos + len);
        }
        pos += len;
    }
}