/*239. 滑动窗口最大值

https://leetcode.cn/problems/sliding-window-maximum/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> r;
        if (nums.size() < k)
        {
            return r;
        }

        priority_queue<int> heap;
        for (int i = 0; i < k; ++i)
        {
            heap.push(nums[i]);
        }

        unordered_map<int, int> m;
        for (int i = 0, j = k - 1; j < nums.size(); ++i, ++j)
        {
            if (i)
            {
                if (heap.top() == nums[i - 1])
                {
                    heap.pop();
                }
                else
                {
                    m[nums[i - 1]]++;
                }
                heap.push(nums[j]);
            }

            while (m.find(heap.top()) != m.end())
            {
                m[heap.top()]--;
                if (m[heap.top()] == 0)
                {
                    m.erase(heap.top());
                }
                heap.pop();
            }
            r.push_back(heap.top());
        }

        return r;
    }
};

int main()
{
    vector<tuple<vector<int>, int>> v{{{1, 3, -1, -3, 5, 3, 6, 7}, 3}, {{1}, 1}, {{9, 10, 9, -7, -4, -8, 2, -6}, 5}};

    for (auto &t : v)
    {
        cout << get<0>(t)[0] << "...," << get<1>(t) << ":\t";
        auto r = Solution().maxSlidingWindow(get<0>(t), get<1>(t));
        for (auto &i : r)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << "done!" << endl;
    return 0;
}
