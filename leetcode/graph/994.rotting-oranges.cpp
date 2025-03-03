/*994. 腐烂的橘子

https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution
{
public:
    int empty = 0;
    int fresh = 1;
    int rotten = 2;
    array<array<int, 2>, 4> neibs{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        queue<array<int, 2>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == rotten)
                {
                    q.push({i, j});
                }
            }
        }

        array<int, 2> arr;
        int count = -1;
        int len, i, j;
        while (!q.empty())
        {
            len = q.size();

            cout << "len: " << len << endl;

            while (len)
            {
                --len;

                arr = q.front();
                q.pop();

                for (auto &neib : neibs)
                {
                    i = arr[0] + neib[0];
                    j = arr[1] + neib[1];
                    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == fresh)
                    {
                        q.push({i, j});
                        grid[i][j] = rotten;
                        cout << "rotten: (" << i << "," << j << ")" << endl;
                    }
                }
            }

            ++count;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == fresh)
                {
                    return -1;
                }
            }
        }

        return count == -1 ? 0 : count;
    }
};

int main()
{
    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << Solution().orangesRotting(grid) << endl;

    cout << "done!" << endl;
    return 0;
}
