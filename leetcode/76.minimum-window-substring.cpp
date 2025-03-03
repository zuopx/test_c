/*76. 最小覆盖子串

https://leetcode.cn/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <array>
#include <iostream>
#include <vector>
using namespace std;

constexpr int len = 'z' - 'A' + 1;

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
        {
            return "";
        }

        array<int, len> a{}, b{};
        for (auto &c : t)
        {
            a[c - 'A']++;
        }

        int x = 0, y = s.size();
        int i = 0, j = 0;
        while (j < s.size())
        {
            b[s[j] - 'A']++;
            bool ok = check(a, b);
            if (!ok)
            {
                ++j;
                continue;
            }

            cout << "[" << i << "," << j << "]"
                 << ",";
            while (i < j)
            {
                if (b[s[i] - 'A'] - 1 >= a[s[i] - 'A'])
                {
                    cout << i << ",";
                    b[s[i] - 'A']--;
                    ++i;
                }
                else
                {
                    break;
                }
            }

            if (j - i < y - x)
            {
                x = i;
                y = j;
                cout << "(" << x << "," << y << "),";
            }

            b[s[i] - 'A']--;
            ++i;
            ++j;
        }

        if (y == s.size())
        {
            return "";
        }

        string r;
        for (int k = x; k <= y; ++k)
        {
            r.push_back(s[k]);
        }
        return r;
    }

    bool check(array<int, len> &a, array<int, len> &b)
    {
        bool ok = true;
        for (int i = 0; i < len; ++i)
        {
            if (a[i] > b[i])
            {
                ok = false;
                break;
            }
        }
        return ok;
    }
};

int main()
{
    vector<vector<string>> v{// {"ADOBECODEBANC", "ABC"},
                             // {"a", "a"},
                             // {"a", "aa"},
                             // {"cabwefgewcwaefgcf", "cae"},
                             {"cgklivwehljxrdzpfdqsapogwvjtvbzahjnsejwnuhmomlfsrv"
                              "mrnczjzjevkdvroiluthhpqtffhlzyglrvorgnalk",
                              "mqfff"}};
    for (auto &strs : v)
    {
        cout << strs[0] << "," << strs[1] << ":\t";
        string r = Solution().minWindow(strs[0], strs[1]);
        cout << r << endl;
    }

    cout << "done!" << endl;
    return 0;
}
