/*226. 翻转二叉树

https://leetcode.cn/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
