/*三数之和

https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-100-liked

先排序，在利用数组的有序特性进行双指针遍历，一个从头开始，一个从末尾开始；在遍历过程中跳过重复值。
*/

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> r;

        sort(nums.begin(), nums.end());

        int *pi, *pj; // 跳过重复值
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pi && *pi == nums[i])
                continue;
            pi = &nums[i];

            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    r.emplace_back(vector<int>{nums[i], nums[j], nums[k]});

                    pj = &nums[j];
                    if (*pj == nums[j] && j < k)
                        ++j;
                    --k;
                }

                j = sum < 0 ? j + 1 : j;
                k = sum > 0 ? k - 1 : k;
            }
        }

        return r;
    }
};

// 被测函数
vector<vector<int>> threeSum(vector<int> &nums)
{
    return Solution().threeSum(nums);
}

// Helper function to normalize a triplet vector
vector<vector<int>> normalize(const vector<vector<int>> &v)
{
    vector<vector<int>> res = v;
    for (auto &triplet : res)
        sort(triplet.begin(), triplet.end());
    sort(res.begin(), res.end());
    return res;
}

// Test cases using standard GTest assertions
TEST(ThreeSumTest, StandardCase)
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}

TEST(ThreeSumTest, AllZeros)
{
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> expected = {{0, 0, 0}};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}

TEST(ThreeSumTest, ExtraZeros)
{
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> expected = {{0, 0, 0}};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}

TEST(ThreeSumTest, EmptyInput)
{
    vector<int> nums = {};
    vector<vector<int>> expected = {};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}

TEST(ThreeSumTest, NoSolution)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> expected = {};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}

TEST(ThreeSumTest, MixedNumbers)
{
    vector<int> nums = {-2, 0, 1, 1, 2};
    vector<vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
    EXPECT_EQ(normalize(threeSum(nums)), normalize(expected));
}