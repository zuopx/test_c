/*114. 二叉树展开为链表

https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
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
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        vector<TreeNode *> v;
        helper(root, v);

        for (int i = 0; i < v.size() - 1; ++i)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        }
        v[v.size() - 1]->left = nullptr;
        v[v.size() - 1]->right = nullptr;
    }

    void helper(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root)
        {
            v.push_back(root);
            helper(root->left, v);
            helper(root->right, v);
        }
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
