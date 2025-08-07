/*139. Word Break

https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-100-liked

f(n) = or { f(n-l) && s.substr(n-l, l) in dict } l in [1, n]

递归、回溯：从上至下
贪心、动态：从下至上
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};