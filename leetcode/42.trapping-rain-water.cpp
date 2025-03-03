/*接雨水

https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
        {
            return 0;
        }

        vector<int> peak;
        for (int i = 0; i < height.size(); ++i)
        {
            if (i == 0)
            {
                if (height[i] > height[i + 1])
                {
                    peak.push_back(i);
                }
            }
            else if (i == height.size() - 1)
            {
                if (height[i] > height[i - 1])
                {
                    peak.push_back(i);
                }
            }
            else
            {
                if (height[i] >= max(height[i - 1], height[i + 1]) && height[i] > min(height[i - 1], height[i + 1]))
                {
                    peak.push_back(i);
                }
            }
        }

        if (peak.size() < 2)
        {
            return 0;
        }

        int topIdx = 0;
        for (int i = 1; i < peak.size(); ++i)
        {
            if (height[peak[i]] > height[peak[topIdx]])
            {
                topIdx = i;
            }
        }

        int area = 0;
        int base = 0;
        for (int i = 1; i <= topIdx; ++i)
        {
            if (height[peak[i]] >= height[peak[base]])
            {
                area += height[peak[base]] * (peak[i] - peak[base] - 1);
                for (int j = peak[base] + 1; j < peak[i]; ++j)
                {
                    area -= min(height[j], height[peak[base]]);
                }
                base = i;
            }
        }

        base = peak.size() - 1;
        for (int i = peak.size() - 2; i >= topIdx; --i)
        {
            if (height[peak[i]] >= height[peak[base]])
            {
                area += height[peak[base]] * (peak[base] - peak[i] - 1);
                for (int j = peak[i] + 1; j < peak[base]; ++j)
                {
                    area -= min(height[j], height[peak[base]]);
                }
                base = i;
            }
        }

        return area;
    }
};

int main()
{
    // vector<int> nums{4, 2, 0, 3, 2, 5};
    vector<int> nums{5, 4, 1, 2};
    // vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int r = Solution().trap(nums);

    cout << r << endl;

    cout << "done!" << endl;
    return 0;
}
