/*105. 从前序与中序遍历序列构造二叉树

https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int begin1, int end1, int begin2, int end2)
    {
        if (begin1 > end1)
        {
            return nullptr;
        }

        if (begin1 == end1)
        {
            return new TreeNode{preorder[begin1]};
        }

        TreeNode *root = new TreeNode{preorder[begin1]};

        int len = 0;
        while (inorder[begin2 + len] != preorder[begin1])
        {
            ++len;
        }

        root->left = _buildTree(preorder, inorder, begin1 + 1, begin1 + len, begin2, begin2 + len - 1);
        root->right = _buildTree(preorder, inorder, begin1 + len + 1, end1, begin2 + len + 1, end2);

        return root;
    }
};

int main()
{
    vector<int> preorder{1, 2, 3};
    vector<int> inorder{3, 2, 1};

    auto root = Solution().buildTree(preorder, inorder);

    cout << "done!" << endl;
    return 0;
}
