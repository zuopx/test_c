/*102. 二叉树的层序遍历

https://leetcode.cn/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> v;

        if (!root)
        {
            return v;
        }

        queue<TreeNode *> q;
        int len;
        q.push(root);
        while (!q.empty())
        {
            vector<int> layer;
            len = q.size();

            while (len)
            {
                --len;

                TreeNode *node = q.front();
                q.pop();

                layer.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            v.push_back(layer);
        }

        return v;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
