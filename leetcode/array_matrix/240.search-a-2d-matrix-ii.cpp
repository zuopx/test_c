/*240. 搜索二维矩阵 II

https://leetcode.cn/problems/search-a-2d-matrix-ii/description/?envType=study-plan-v2&envId=top-100-liked

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

缩减解空间：
从右上角位置开始搜索，如果当前元素小于目标值，则排除当前行，如果当前元素大于目标值，则排除当前列。
*/

#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;

        int m = matrix[0].size();
        int r = 0, c = m - 1, num;
        while (r < n && c >= 0)
        {
            num = matrix[r][c];
            if (num == target)
                return true;
            else if (num < target)
                ++r;
            else
                --c;
        }
        return false;
    }
};

// 被测试的包装函数
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    return Solution().searchMatrix(matrix, target);
}

// 测试套件
class SearchMatrixTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // 测试前准备
    }

    void TearDown() override
    {
        // 测试后清理
    }
};

// Test Case 1: 空矩阵测试
// Test empty matrix scenario
TEST_F(SearchMatrixTest, EmptyMatrix)
{
    vector<vector<int>> matrix = {};
    int target = 5;

    // 预期返回false
    EXPECT_FALSE(searchMatrix(matrix, target));
}

// Test Case 2: 单行矩阵测试
// Test single row matrix scenario
TEST_F(SearchMatrixTest, SingleRowMatrix)
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}};
    int target = 3;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 3: 单列矩阵测试
// Test single column matrix scenario
TEST_F(SearchMatrixTest, SingleColumnMatrix)
{
    vector<vector<int>> matrix = {{1}, {3}, {5}};
    int target = 3;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 4: 目标值存在测试
// Test target value exists scenario
TEST_F(SearchMatrixTest, TargetExists)
{
    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}};
    int target = 9;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 5: 目标值不存在测试
// Test target value not exists scenario
TEST_F(SearchMatrixTest, TargetNotExists)
{
    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}};
    int target = 6;

    // 预期返回false
    EXPECT_FALSE(searchMatrix(matrix, target));
}

// Test Case 6: 边界值最小值测试
// Test boundary value - minimum value
TEST_F(SearchMatrixTest, BoundaryMinimumValue)
{
    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}};
    int target = 1;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 7: 边界值最大值测试
// Test boundary value - maximum value
TEST_F(SearchMatrixTest, BoundaryMaximumValue)
{
    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}};
    int target = 11;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 8: 大矩阵测试
// Test large matrix scenario
TEST_F(SearchMatrixTest, LargeMatrix)
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16}};
    int target = 5;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 9: 负数矩阵测试
// Test matrix with negative numbers
TEST_F(SearchMatrixTest, NegativeNumbers)
{
    vector<vector<int>> matrix = {{-3, -1, 0}, {1, 3, 5}};
    int target = -1;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// Test Case 10: 零值测试
// Test zero value target
TEST_F(SearchMatrixTest, ZeroTarget)
{
    vector<vector<int>> matrix = {{-1, 0, 1}, {2, 3, 4}};
    int target = 0;

    // 预期返回true
    EXPECT_TRUE(searchMatrix(matrix, target));
}

// 性能测试示例
// Performance test example
TEST_F(SearchMatrixTest, PerformanceTest)
{
    vector<vector<int>> matrix(100, vector<int>(100));

    // 填充数据
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            matrix[i][j] = i * 100 + j;
        }
    }

    int target = 5050;

    // 测试执行时间
    auto start = chrono::high_resolution_clock::now();
    bool result = searchMatrix(matrix, target);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    EXPECT_TRUE(result);
    // 验证执行时间在合理范围内（例如小于100ms）
    EXPECT_LT(duration.count(), 100000); // 100ms
}