/*104. 二叉树的最大深度

https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode *root)
    {
        return _maxDepth(root);
    }

    int _maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return 1;
        }

        return 1 + max(_maxDepth(root->left), _maxDepth(root->right));
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
