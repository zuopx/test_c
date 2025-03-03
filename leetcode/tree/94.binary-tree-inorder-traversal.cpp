/*94.二叉树的中序遍历

https://leetcode.cn/problems/binary-tree-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> r;

        _inorderTraversal(root, r);

        return r;
    }

    void _inorderTraversal(TreeNode *root, vector<int> &r)
    {
        if (root)
        {
            _inorderTraversal(root->left, r);
            r.push_back(root->val);
            _inorderTraversal(root->right, r);
        }
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
