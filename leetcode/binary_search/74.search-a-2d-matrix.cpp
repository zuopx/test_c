/*74. 搜索二维矩阵

https://leetcode.cn/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-100-liked
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

        int i = 0, j = n * m;
        int mid, midVal;
        while (i < j)
        {
            mid = (i + j) / 2;
            midVal = matrix[mid / m][mid % m];

            if (target == midVal)
            {
                return true;
            }
            else if (target < midVal)
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 3, 5, 7}, {23, 30, 34, 60}, {23, 30, 34, 60}};
    cout << Solution().searchMatrix(matrix, 3) << endl;
    cout << Solution().searchMatrix(matrix, 13) << endl;

    cout << "done!" << endl;
    return 0;
}
