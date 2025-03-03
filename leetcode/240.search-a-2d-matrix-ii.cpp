/*240. 搜索二维矩阵 II

https://leetcode.cn/problems/search-a-2d-matrix-ii/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = m - 1, num;
        while (r < n && c >= 0)
        {
            num = matrix[r][c];
            if (num == target)
            {
                return true;
            }
            else if (num < target)
            {
                ++r;
            }
            else
            {
                --c;
            }
        }
        return false;
    }
};

int main()
{

    vector<pair<vector<vector<int>>, int>> v{
        {{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 5},
        {{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 20},
    };
    for (auto &p : v)
    {
        auto matrix = p.first;
        cout << matrix[0][0] << "...: ";
        cout << Solution().searchMatrix(matrix, p.second);
        cout << endl;
    }

    cout << "done!" << endl;
    return 0;
}
