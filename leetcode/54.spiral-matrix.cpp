/*54. 螺旋矩阵

https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> v;

        _spiralOrder(matrix, v, 0, matrix.size(), 0, matrix[0].size());

        return v;
    }

    void _spiralOrder(vector<vector<int>> &matrix, vector<int> &v, int row1, int row2, int col1, int col2)
    {
        if (!(row2 > row1 && col2 > col1))
        {
            return;
        }

        int c, r;

        if (row2 - row1 == 1)
        {
            for (c = col1; c < col2; ++c)
            {
                v.push_back(matrix[row1][c]);
            }
            return;
        }
        if (col2 - col1 == 1)
        {
            for (r = row1; r < row2; ++r)
            {
                v.push_back(matrix[r][col1]);
            }
            return;
        }

        for (c = col1; c < col2; ++c)
        {
            v.push_back(matrix[row1][c]);
        }
        for (r = row1 + 1; r < row2 - 1; ++r)
        {
            v.push_back(matrix[r][col2 - 1]);
        }
        for (c = col2 - 1; c >= col1; --c)
        {
            v.push_back(matrix[row2 - 1][c]);
        }
        for (r = row2 - 2; r >= row1 + 1; --r)
        {
            v.push_back(matrix[r][col1]);
        }
        _spiralOrder(matrix, v, row1 + 1, row2 - 1, col1 + 1, col2 - 1);
    }
};

int main()
{
    vector<vector<vector<int>>> v{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};

    for (auto &matrix : v)
    {
        cout << matrix[0][0] << "...: ";
        auto r = Solution().spiralOrder(matrix);
        for (auto &num : r)
        {
            cout << num << ",";
        }
        cout << endl;
    }

    cout << "done!" << endl;
    return 0;
}