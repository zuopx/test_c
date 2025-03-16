/*739. 每日温度

https://leetcode.cn/problems/daily-temperatures/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T = int> void printVector(vector<T> &nums)
{
    for (T &num : nums)
    {
        cout << num << ",";
    }
    cout << endl;
}

class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st1, st2;

        int num;
        for (int i = 0; i < temperatures.size(); ++i)
        {
            num = temperatures[i];
            while (!st1.empty() && num > st1.top())
            {
                ans[st2.top()] = i - st2.top();
                st1.pop();
                st2.pop();
            }

            st1.push(num);
            st2.push(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = Solution().dailyTemperatures(temperatures);
    printVector(ans);

    cout << "done!" << endl;
    return 0;
}
