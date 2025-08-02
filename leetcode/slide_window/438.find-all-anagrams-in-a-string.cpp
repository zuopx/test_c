/*438. 找到字符串中所有字母异位词

https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <array>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> r;
        if (s.size() < p.size())
        {
            return r;
        }

        array<int, 26> a{}, b{}; // 必须要执行初始化
        for (int i = 0; i < p.size(); ++i)
        {
            a[p[i] - 'a']++;
            b[s[i] - 'a']++;
        }

        for (int i = 0, j = p.size() - 1; j < s.size(); ++i, ++j)
        {
            if (i)
            {
                b[s[i - 1] - 'a']--;
                b[s[j] - 'a']++;
            }

            if (a == b)
            {
                r.push_back(i);
            }
        }

        return r;
    }
};

int main()
{
    vector<array<string, 2>> strs{{"cbaebabacd", "abc"}, {"abab", "ab"}};
    for (auto &arr : strs)
    {
        cout << arr[0] << ", " << arr[1] << ":\t";
        auto r = Solution().findAnagrams(arr[0], arr[1]);
        for (auto &i : r)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << "done!" << endl;
    return 0;
}
