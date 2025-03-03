/*207. 课程表

https://leetcode.cn/problems/course-schedule/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> s3;

        while (true)
        {
            s1.clear();
            s2.clear();

            for (auto &req : prerequisites)
            {
                if (s3.find(req[1]) == s3.end())
                {
                    s1.insert(req[0]);
                    s2.insert(req[1]);
                }
            }

            int len = s3.size();
            for (auto &num : s2)
            {
                if (s1.find(num) == s1.end())
                {
                    s3.insert(num);
                }
            }

            if (s3.size() == len)
            {
                break;
            }
        }

        for (auto &req : prerequisites)
        {
            if (s3.find(req[1]) == s3.end())
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> prerequisites{{1, 0}, {0, 1}};

    cout << Solution().canFinish(2, prerequisites) << endl;

    cout << "done!" << endl;
    return 0;
}
