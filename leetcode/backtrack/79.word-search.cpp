/*79. 单词搜索*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<bool> visited(n * m, false);
        bool found = false;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!found)
                {
                    dfs(board, word, i, j, 0, visited, found);
                }
            }
        }

        return found;
    }

    void dfs(vector<vector<char>> &board, string &word, int i, int j, int idx, vector<bool> &visited, bool &found)
    {
        if (idx == word.size())
        {
            found = true;
            return;
        }

        int n = board.size(), m = board[0].size();
        if (found || i < 0 || i >= n || j < 0 || j >= m || visited[i * m + j] || board[i][j] != word[idx])
        {
            return;
        }

        cout << "(" << i << "," << j << "): " << word[idx] << endl;

        visited[i * m + j] = true;
        dfs(board, word, i + 1, j, idx + 1, visited, found);
        dfs(board, word, i - 1, j, idx + 1, visited, found);
        dfs(board, word, i, j + 1, idx + 1, visited, found);
        dfs(board, word, i, j - 1, idx + 1, visited, found);
        visited[i * m + j] = false;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    Solution().exist(board, word);

    cout << "done!" << endl;
    return 0;
}
