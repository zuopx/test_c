/*118. 杨辉三角

https://leetcode.cn/problems/pascals-triangle/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;

        res.push_back(vector<int>{1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; j++)
            {
                row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            row.push_back(1);
            res.push_back(row);
        }

        return res;
    }
};