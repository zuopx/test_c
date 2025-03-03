/*236. 二叉树的最近公共祖先

https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <stack>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        bool find1 = true, find2 = true;
        helper(root, p, st1, find1);
        helper(root, q, st2, find2);

        stack<TreeNode *> st3;
        stack<TreeNode *> st4;
        while (!st1.empty())
        {
            st3.push(st1.top());
            st1.pop();
        }
        while (!st2.empty())
        {
            st4.push(st2.top());
            st2.pop();
        }

        stack<TreeNode *> st5;
        while (!st3.empty() && !st4.empty())
        {
            if (st3.top() == st4.top())
            {
                st5.push(st3.top());
                st3.pop();
                st4.pop();
            }
            else
            {
                break;
            }
        }

        return st5.top();
    }

    void helper(TreeNode *root, TreeNode *node, stack<TreeNode *> &st, bool &find)
    {
        if (root && find)
        {
            st.push(root);
            find = (root != node);

            helper(root->left, node, st, find);
            helper(root->right, node, st, find);

            if (find)
            {
                st.pop();
            }
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode{
        3,
        new TreeNode{
            5,
            new TreeNode{6},
            new TreeNode{2, new TreeNode{7}, new TreeNode{4}}},
        new TreeNode{1, new TreeNode{0}, new TreeNode{8}}};

    TreeNode *node;
    node = Solution().lowestCommonAncestor(root, root->left, root->right);
    cout << node->val << endl;
    node = Solution().lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << node->val << endl;

    cout << "done!" << endl;
    return 0;
}
