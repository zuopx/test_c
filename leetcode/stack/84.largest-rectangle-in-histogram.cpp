/*84. 柱状图中最大的矩形

https://leetcode.cn/problems/largest-rectangle-in-histogram/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st1, st2;
        st1.push(-1);
        st2.push(-1);
        heights.push_back(-1);

        int maxArea = 0;

        int height, topVal, topIdx, topArea;
        for (int i = 0; i < heights.size(); ++i)
        {
            height = heights[i];

            while (height < st1.top())
            {
                topVal = st1.top();
                topIdx = st2.top();
                st1.pop();
                st2.pop();

                topArea = topVal * (i - 1 - st2.top());
                maxArea = max(maxArea, topArea);

                cout << topIdx << ": " << topArea << " = " << topVal << " * " << "(" << i - 1 << " - " << st2.top() << ")" << endl;
            }

            st1.push(height);
            st2.push(i);
        }

        return maxArea;
    }
};

int main()
{
    vector<int> heights{6, 7, 5, 2, 4, 5, 9, 3};
    cout << Solution().largestRectangleArea(heights) << endl;

    cout << "done!" << endl;
    return 0;
}
