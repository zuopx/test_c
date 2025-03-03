/*73. 矩阵置零

https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }

        for (auto &row : rowSet)
        {
            for (int j = 0; j < m; ++j)
            {
                matrix[row][j] = 0;
            }
        }
        for (auto &col : colSet)
        {
            for (int i = 0; i < n; ++i)
            {
                matrix[i][col] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<vector<int>>> v{{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}};

    for (auto &matrix : v)
    {
        cout << matrix[0][0] << "...: ";
        Solution().setZeroes(matrix);
        for (auto &nums : matrix)
        {
            cout << "[";
            for (auto &num : nums)
            {
                cout << num << ",";
            }
            cout << "],";
        }
        cout << endl;
    }

    cout << "done!" << endl;
    return 0;
}
