/*22.括号生成*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string str;

        helper(n, n, 0, str, ans);

        return ans;
    }

    void helper(int left, int right, int valid, string &str, vector<string> &ans)
    {
        if (valid < 0 || left < 0 || right < 0)
        {
            return;
        }

        if (left == 0 && right == 0)
        {
            ans.push_back(str);
            cout << str << endl;
            return;
        }

        str.push_back('(');
        helper(left - 1, right, valid + 1, str, ans);
        str.pop_back();

        str.push_back(')');
        helper(left, right - 1, valid - 1, str, ans);
        str.pop_back();
    }
};

int main()
{
    Solution().generateParenthesis(3);

    cout << "done!" << endl;
    return 0;
}
