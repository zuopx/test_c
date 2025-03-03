/*437. 路径总和 III

https://leetcode.cn/problems/path-sum-iii/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int count = 0;
        long long num = targetSum;
        _pathSum(root, num, count);

        return count;
    }

    void _pathSum(TreeNode *root, long long &targetSum, int &count)
    {
        if (root)
        {
            int a = helper(root, targetSum);
            count += a;
            cout << root->val << ": " << a << endl;
            _pathSum(root->left, targetSum, count);
            _pathSum(root->right, targetSum, count);
        }
    }

    int helper(TreeNode *root, long long targetSum)
    {
        if (!root)
        {
            return 0;
        }

        return (root->val == targetSum) + helper(root->left, targetSum - root->val) + helper(root->right, targetSum - root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode{
        10,
        new TreeNode{
            5,
            new TreeNode{3, new TreeNode{3}, new TreeNode{-2}},
            new TreeNode{2, nullptr, new TreeNode{1}}},
        new TreeNode{-3, nullptr, new TreeNode{11}}};

    Solution().pathSum(root, 8);

    cout << "done!" << endl;
    return 0;
}
