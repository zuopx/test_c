/**/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &ch : s)
        {
            if (ch == '{' || ch == '[' || ch == '(')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                if ((ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '('))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    cout << Solution().isValid("()") << endl;
    cout << Solution().isValid("()[]{}") << endl;
    cout << Solution().isValid("(]") << endl;
    cout << Solution().isValid("([])") << endl;
    cout << "done!" << endl;
    return 0;
}
