/*279. 完全平方数

https://leetcode.cn/problems/perfect-squares/description/?envType=study-plan-v2&envId=top-100-liked

f(n) = 1 + min(f(n-j*j)), j=1...sqrt(n)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 暴力解法
    int numSquares(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int ans = n;
        for (int i = 1; i * i <= n; i++)
            ans = min(ans, numSquares(n - i * i));
        return ans + 1;
    }

    // 动态规划，降低时间复杂度
    int numSquares2(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
