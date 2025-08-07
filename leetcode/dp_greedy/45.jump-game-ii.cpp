/*45. 跳跃游戏 II

https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-100-liked
返回到达 nums[n - 1] 的最小跳跃次数。

假设已调到位置i，位置i可跳到j，j满足j<=i+nums[i]，那么到底该跳到那个位置呢？
贪心算法：追求j+nums[j]最大
*/
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i == nums.size() - 1)
                return 0;
            if (i + nums[i] >= nums.size() - 1)
                return 1;

            int max_jump = i + 1;
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++)
                if (j + nums[j] > max_jump + nums[max_jump])
                    max_jump = j;
            return 1 + dfs(max_jump);
        };

        return dfs(0);
    }

    int jump1(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;

        int curr = 0;
        int step = 1;
        while (curr + nums[curr] < nums.size() - 1)
        {
            int next = curr + 1;
            for (int i = curr + 1; i < nums.size() && i <= curr + nums[curr]; i++)
                if (i + nums[i] > next + nums[next])
                    next = i;
            curr = next;
            step++;
        }

        return step;
    }
};

// 被测函数声明
int jump(vector<int> &nums)
{
    return Solution().jump1(nums);
}

// Test suite for jump function
class JumpTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup code if needed
    }

    void TearDown() override
    {
        // Cleanup code if needed
    }
};

// Test case 1: Basic test case from problem description
// 测试用例1：来自题目描述的基本测试
TEST_F(JumpTest, BasicTestCase)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    EXPECT_EQ(2, jump(nums)); // 从索引0跳到1，再跳到末尾
}

// Test case 2: Another example from problem description
// 测试用例2：题目描述的另一个例子
TEST_F(JumpTest, AnotherExample)
{
    vector<int> nums = {2, 3, 0, 1, 4};
    EXPECT_EQ(2, jump(nums)); // 从索引0跳到1，再跳到末尾
}

// Test case 3: Single element array
// 测试用例3：单元素数组
TEST_F(JumpTest, SingleElement)
{
    vector<int> nums = {0};
    EXPECT_EQ(0, jump(nums)); // 不需要跳跃
}

// Test case 4: Two elements array
// 测试用例4：两元素数组
TEST_F(JumpTest, TwoElements)
{
    vector<int> nums = {2, 1};
    EXPECT_EQ(1, jump(nums)); // 一步到位
}

// Test case 5: All ones - need to jump step by step
// 测试用例5：全为1的情况 - 需要逐步跳跃
TEST_F(JumpTest, AllOnes)
{
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(3, jump(nums)); // 三步跳跃
}

// Test case 6: Can reach end in one jump
// 测试用例6：一步可以到达终点
TEST_F(JumpTest, OneJumpToEnd)
{
    vector<int> nums = {5, 1, 1, 1, 1};
    EXPECT_EQ(1, jump(nums)); // 一步到位
}

// Test case 7: Larger array test
// 测试用例7：较大数组测试
TEST_F(JumpTest, LargerArray)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(3, jump(nums)); // 需要三次跳跃
}

// Test case 8: Maximum values test
// 测试用例8：最大值测试
TEST_F(JumpTest, MaximumValues)
{
    vector<int> nums = {100, 0, 0, 0, 0};
    EXPECT_EQ(1, jump(nums)); // 一步到位
}