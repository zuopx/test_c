/*17. 电话号码的字母组合*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<char>> num2letters = {
    {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}},
};

class Solution
{

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        helper(digits, 0, ans);
        return ans;
    }

    void helper(string digits, int idx, vector<string> &ans)
    {
        if (idx && idx == digits.size())
        {
            ans.push_back(digits);
            cout << digits << endl;
            return;
        }

        for (auto &ch : num2letters[digits[idx] - '0'])
        {
            digits[idx] = ch;
            helper(digits, idx + 1, ans);
        }
    }
};

int main()
{
    Solution().letterCombinations("23");

    cout << "done!" << endl;
    return 0;
}
