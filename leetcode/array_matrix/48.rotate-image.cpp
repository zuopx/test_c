/*48. 旋转图像

https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked

找规律：旋转图像，可以用旋转矩阵

使用技巧，先转置，在垂直翻转
*/
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// Original wrapper function implementation (modified for testing)
class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        // Original implementation would go here
        // For testing purposes, we'll just reverse rows and transpose
        int n = matrix.size();
        if (n <= 1)
            return;

        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++)
        {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Wrapper function to test
void rotate(std::vector<std::vector<int>> &matrix)
{
    return Solution().rotate(matrix);
}

// Test fixture
class RotateFunctionTest : public testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

// Test case 2: Test actual rotation functionality with real implementation
TEST(RotateFunctionIntegrationTest, Rotates2x2MatrixCorrectly)
{
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> expected = {{3, 1}, {4, 2}};

    rotate(matrix);

    EXPECT_EQ(matrix, expected);
}

// Test case 3: Test 3x3 matrix rotation
TEST(RotateFunctionIntegrationTest, Rotates3x3MatrixCorrectly)
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> expected = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

    rotate(matrix);

    EXPECT_EQ(matrix, expected);
}

// Test case 4: Test empty matrix
TEST(RotateFunctionIntegrationTest, HandlesEmptyMatrix)
{
    std::vector<std::vector<int>> matrix = {};

    // Should not crash
    rotate(matrix);

    EXPECT_EQ(matrix.size(), 0);
}

// Test case 5: Test single element matrix
TEST(RotateFunctionIntegrationTest, HandlesSingleElementMatrix)
{
    std::vector<std::vector<int>> matrix = {{1}};
    std::vector<std::vector<int>> expected = {{1}};

    rotate(matrix);

    EXPECT_EQ(matrix, expected);
}

// Test case 6: Test 4x4 matrix rotation
TEST(RotateFunctionIntegrationTest, Rotates4x4MatrixCorrectly)
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    std::vector<std::vector<int>> expected = {
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}};

    rotate(matrix);

    EXPECT_EQ(matrix, expected);
}