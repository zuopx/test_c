/*48. 旋转图像

https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        _rotate(matrix, 0);
    }

    void _rotate(vector<vector<int>> &matrix, int row)
    {
        cout << row << ",";

        int n = matrix.size();
        if (row >= n - 1)
        {
            return;
        }

        int col = n - row;

        int k, r, c;
        vector<int> tmp;
        for (r = n - 1; r >= row; --r)
        {
            tmp.push_back(matrix[r][0]);
        }
        for (r = row + 1; r < n; ++r)
        {
            for (c = 0; c < col - 1; ++c)
            {
                matrix[r][c] = matrix[r][c + 1];
            }
        }

        for (r = n - 1; r >= row; --r)
        {
            matrix[r][col - 1] = matrix[row][r - row];
        }
        for (c = 0; c < col; ++c)
        {
            matrix[row][c] = tmp[c];
        }

        _rotate(matrix, row + 1);
    }
};

int main()
{
    vector<vector<vector<int>>> v{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                                  {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}};

    for (auto &matrix : v)
    {
        cout << matrix[0][0] << "...: ";
        Solution().rotate(matrix);
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
