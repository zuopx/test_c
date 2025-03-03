/*无重复字符串的最长字串

https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;

        int x = 0, y = 0;
        int i = 0, j = 0;
        while (j < s.size())
        {
            if (m.find(s[j]) != m.end() && m[s[j]] >= i)
            {
                if (j - i > y - x)
                {
                    x = i;
                    y = j;
                    // cout << x << "," << y << endl;
                }
                i = m[s[j]] + 1;
                // cout << i << endl;
            }
            m[s[j]] = j;
            ++j;
        }
        if (j - i > y - x)
        {
            x = i;
            y = j;
            // cout << x << "," << y << endl;
        }

        return y - x;
    }
};

int main()
{
    vector<string> strs{"abcabcbb", "bbbbb", "pwwkew", " ", "abba"};
    for (auto &s : strs)
    {
        cout << s << ":\n";
        cout << Solution().lengthOfLongestSubstring(s) << endl;
        cout << "\n\n";
    }

    cout << "done!" << endl;
    return 0;
}
