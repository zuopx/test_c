/*32. Longest Valid Parentheses

https://leetcode.cn/problems/longest-valid-parentheses/?envType=study-plan-v2&envId=top-100-liked
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    char left = '(';
    char right = ')';

    int longestValidParentheses(string s)
    {
        vector<pair<char, int>> stack;
        vector<pair<int, int>> intervals;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (c == right && !stack.empty() && stack.back().first == left)
            {
                intervals.push_back({stack.back().second, i});
                stack.pop_back();
            }
            else
            {
                stack.push_back({c, i});
            }
        }

        if (intervals.empty())
            return 0;
        cout << intervals.size() << endl;

        int res = 0;
        int high = intervals.back().second, low = intervals.back().first;
        for (int i = intervals.size() - 1; i >= 0; i--)
        {
            if (intervals[i].second >= low - 1)
            {
                low = intervals[i].first;
            }
            else
            {
                res = max(res, high - low + 1);
                high = intervals[i].second;
                low = intervals[i].first;
            }
        }

        return max(res, high - low + 1);
    }
};