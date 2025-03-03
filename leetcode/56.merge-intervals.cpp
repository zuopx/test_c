/*56.合并区间

https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<vector<int>> r;

        sort(intervals.begin(), intervals.end());

        int i = 0, j = 1;
        vector<int> *range1, *range2;
        while (j < intervals.size())
        {
            range1 = &intervals[i];
            range2 = &intervals[j];

            if ((*range1)[0] <= (*range2)[0] && (*range2)[0] <= (*range1)[1])
            {
                (*range2)[0] = (*range1)[0];
                (*range2)[1] = max((*range1)[1], (*range2)[1]);
            }
            else
            {
                r.emplace_back(*range1);
            }
            ++i;
            ++j;
        }
        r.emplace_back(*range2);

        return r;
    }
};

int main()
{
    vector<vector<int>> intervals{{{1, 3}, {2, 6}, {8, 10}, {15, 18}}};
    auto r = Solution().merge(intervals);

    for (auto &nums : r)
    {
        cout << "[";
        for (auto &num : nums)
        {
            cout << num << ",";
        }
        cout << "],";
    }
    cout << endl;

    cout << "done!" << endl;
    return 0;
}
