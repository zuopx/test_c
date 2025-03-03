/*200. 岛屿数量

https://leetcode.cn/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ArrayHash
{
    size_t operator()(const array<int, 2> &arr) const
    {
        return hash<int>()(arr[0]) ^ (hash<int>()(arr[1]) << 1);
    }
};

class Solution
{
public:
    char land = '1';
    char water = '0';
    array<array<int, 2>, 4> neibs{array<int, 2>{-1, 0}, array<int, 2>{1, 0}, array<int, 2>{0, -1}, array<int, 2>{0, 1}};

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        unordered_set<array<int, 2>, ArrayHash> s;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == land)
                {
                    s.insert({i, j});
                    cout << "insert: (" << i << "," << j << ")" << endl;
                }
            }
        }

        int count = 0;
        int i, j;
        while (!s.empty())
        {
            array<int, 2> arr = *s.begin();
            s.erase(arr);
            cout << "erase: (" << arr[0] << "," << arr[1] << ")" << endl;

            queue<array<int, 2>> q;
            q.push(arr);

            while (!q.empty())
            {
                arr = q.front();
                q.pop();

                for (auto &neib : neibs)
                {
                    i = arr[0] + neib[0];
                    j = arr[1] + neib[1];
                    if (s.find({i, j}) != s.end())
                    {
                        q.push({i, j});
                        s.erase({i, j});
                        cout << "erase: (" << i << "," << j << ")" << endl;
                    }
                }
            }
            ++count;
        }

        return count;
    }
};

int main()
{

    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << Solution().numIslands(grid) << endl;

    cout << "done!" << endl;
    return 0;
}
