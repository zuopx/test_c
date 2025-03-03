/*199. 二叉树的右视图

https://leetcode.cn/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <queue>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;

        if (!root)
        {
            return v;
        }

        queue<TreeNode *> q;
        int len;
        TreeNode *node;

        q.push(root);
        while (!q.empty())
        {
            v.push_back(q.front()->val);

            len = q.size();
            while (len)
            {
                --len;

                node = q.front();
                q.pop();

                if (node->right)
                {
                    q.push(node->right);
                }
                if (node->left)
                {
                    q.push(node->left);
                }
            }
        }

        return v;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
