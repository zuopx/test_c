/*49. 字母异位词分组

https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
    输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
    输入: strs = [""]
    输出: [[""]]
示例 3:
    输入: strs = ["a"]
    输出: [["a"]]
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> r;
        unordered_map<string, vector<string>> m;

        int i = 0;
        for (auto s : strs)
        {
            sort(s.begin(), s.end());

            if (m.find(s) != m.end())
            {
                m[s].emplace_back(strs[i]);
            }
            else
            {
                m[s] = vector<string>{strs[i]};
            }

            i++;
        }

        for (auto &i : m)
        {
            r.emplace_back(i.second);
        }

        return r;
    }
};

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto r = Solution().groupAnagrams(strs);

    for (auto &s : strs)
    {
        cout << s << endl;
    }

    for (auto &strs : r)
    {
        for (auto &s : strs)
        {
            cout << s << endl;
        }
    }

    return 0;
}
