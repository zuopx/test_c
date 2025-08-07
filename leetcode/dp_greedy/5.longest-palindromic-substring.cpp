/*5. Longest Palindromic Substring

https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-100-liked

f(i,j) = f(i+1,j-1) && s[i] == s[j]
*/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0, max_len = 1;

        for (int diff = 0; diff < s.size(); ++diff)
        {
            for (int i = 0, j = i + diff; j < s.size(); ++i, ++j)
            {
                if (diff <= 1)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j] && max_len < diff + 1)
                {
                    start = i;
                    max_len = diff + 1;
                }
            }
        }

        return s.substr(start, max_len);
    }
};