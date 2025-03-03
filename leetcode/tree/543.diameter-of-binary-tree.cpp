/*543. 二叉树的直径

https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <unordered_map>
#include <vector>
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        unordered_map<TreeNode *, int> m;
        int len = 0;

        depth(root, m, len);

        return len;
    }

    int depth(TreeNode *root, unordered_map<TreeNode *, int> &m, int &len)
    {
        if (!root)
        {
            return 0;
        }

        auto iter = m.find(root);
        if (iter != m.end())
        {
            return iter->second;
        }

        int left = depth(root->left, m, len), right = depth(root->right, m, len);
        int d = 1 + max(left, right);

        m[root] = d;
        len = max(len, left + right);

        return d;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
