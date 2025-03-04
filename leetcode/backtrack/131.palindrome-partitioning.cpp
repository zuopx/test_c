/*131. 分割回文串*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> strs;

        helper(s, 0, strs, ans);

        return ans;
    }

    void helper(string &s, int idx, vector<string> &strs, vector<vector<string>> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(strs);
            for (auto &str : strs)
            {
                cout << str << ",";
            }
            cout << endl;
            return;
        }

        for (int i = idx; i < s.size(); ++i)
        {
            string substr = s.substr(idx, i - idx + 1);
            if (isPalindrome(substr))
            {
                strs.push_back(substr);
                helper(s, i + 1, strs, ans);
                strs.pop_back();
            }
        }
    }

    bool isPalindrome(string &str)
    {
        int len = str.size();
        for (int i = 0; i < len / 2 + 1; ++i)
        {
            if (str[i] != str[len - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s = "aab";
    // cout << s.substr(0, 1) << endl;
    // cout << s.substr(1, 2) << endl;
    Solution().partition(s);

    cout << "done!" << endl;
    return 0;
}
