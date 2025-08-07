/*322. Coin Change

https://leetcode.cn/problems/coin-change/description/?envType=study-plan-v2&envId=top-100-liked

f(n) = 1 + min(f(n-coin), f(n-coin2), ...)
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int &coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
