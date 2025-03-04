/**/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
  public:
    string decodeString(string s)
    {
        stack<string> st;
        string str;
        string str2;
        string str3;
        int i, num;

        for (auto &ch : s)
        {
            if (ch != ']')
            {
                st.push(string(1, ch));
                continue;
            }

            str.clear();
            while (st.top() != "[")
            {
                str.append(st.top());
                st.pop();
            }
            st.pop();

            i = 1;
            num = 0;
            while (!st.empty() && isdigit(st.top()[0]))
            {
                num = num + i * (st.top()[0] - '0');
                i = i * 10;
                st.pop();
            }

            str2.clear();
            while (num)
            {
                --num;
                str2.append(str);
            }
            st.push(str2);
        }

        while (!st.empty())
        {
            str3.append(st.top());
            st.pop();
        }
        reverse(str3.begin(), str3.end());

        return str3;
    }
};

int main()
{

    cout << Solution().decodeString("3[a]2[bc]") << endl;
    cout << Solution().decodeString("3[a2[c]]") << endl;
    cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
    cout << Solution().decodeString("abc3[cd]xyz") << endl;
    cout << Solution().decodeString("10[cd]") << endl;

    cout << "done!" << endl;
    return 0;
}
