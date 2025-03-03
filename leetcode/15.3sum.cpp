/*三数之和

https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum1(vector<int> &nums)
    {
        vector<vector<int>> r;

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<array<int, 2>>> m;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                m[nums[i] + nums[j]].emplace_back(array<int, 2>{i, j});
            }
        }

        for (auto &p : m)
        {
            cout << p.first << ":\t";
            for (auto &a : p.second)
            {
                cout << "(" << a[0] << "," << a[1] << ")"
                     << ",";
            }
            cout << endl;
        }

        unordered_set<int> set1;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            if (set1.count(num))
            {
                continue;
            }
            set1.insert(num);

            if (m.find(-num) != m.end())
            {
                unordered_set<int> set2;
                for (auto &a : m[-num])
                {
                    if (set2.count(nums[a[0]]) or i >= a[0])
                    {
                        continue;
                    }
                    set2.insert(nums[a[0]]);
                    cout << "(" << i << "," << a[0] << "," << a[1] << ")"
                         << ":";
                    cout << "(" << num << "," << nums[a[0]] << "," << nums[a[1]] << ")" << endl;
                    r.emplace_back(vector<int>{num, nums[a[0]], nums[a[1]]});
                }
            }
        }

        return r;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> r;

        sort(nums.begin(), nums.end());

        unordered_set<int> set1, set2;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (set1.count(nums[i]))
                continue;
            set1.insert(nums[i]);

            int j = i + 1, k = nums.size() - 1;
            set2.clear();
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    // cout << "(" << nums[i] << "," << nums[j] << "," << nums[k] << ")"
                    // << endl;
                    r.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    set2.insert(nums[j]);
                    while (set2.count(nums[j]) && j < k)
                        ++j;
                    --k;
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }

        return r;
    }
};

int main()
{
    // vector<int> nums{-1, -1, 0, 0, 0, 1, 1, 2, -1, -4};
    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<int> nums{0, 0, 0, 0};

    auto r = Solution().threeSum(nums);

    for (auto &v : r)
    {
        for (auto &i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }

    cout << "done!" << endl;
    return 0;
}
