/*1143. Longest Common Subsequence

https://leetcode.cn/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=top-100-liked

f(i,j) = max(f(i-1,j-1) + 1 if text1[i] == text2[j], f(i-1,j), f(i,j-1))
*/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};