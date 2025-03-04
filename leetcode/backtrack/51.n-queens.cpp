/*51. N 皇后*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> strs;
        vector<bool> opened(5 * n, true);

        helper(n, 0, strs, opened, ans);

        return ans;
    }

    void helper(int n, int row, vector<string> &strs, vector<bool> &opened, vector<vector<string>> &ans)
    {
        if (row == n)
        {
            ans.push_back(strs);
            for (auto &str : strs)
            {
                cout << str << ",";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < n; ++i)
        {

            if (opened[i] && opened[row - i + n + n] && opened[row + i + 3 * n])
            {
                string str(n, '.');
                str[i] = 'Q';
                strs.push_back(str);
                opened[i] = false;
                opened[row - i + n + n] = false;
                opened[row + i + 3 * n] = false;
                helper(n, row + 1, strs, opened, ans);
                opened[i] = true;
                opened[row - i + n + n] = true;
                opened[row + i + 3 * n] = true;
                strs.pop_back();
            }
        }
    }
};

int main()
{
    Solution().solveNQueens(1);
    cout << "done!" << endl;
    return 0;
}
