/*101. 对称二叉树

https://leetcode.cn/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-100-liked
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
    bool isSymmetric(TreeNode *root)
    {
        return _isSymmetric(root->left, root->right);
    }

    bool _isSymmetric(TreeNode *left, TreeNode *right)
    {
        return (!left && !right) || (left && right && left->val == right->val && _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left));
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
