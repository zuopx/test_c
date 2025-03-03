/*124. 二叉树中的最大路径和

https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<TreeNode *, int> m1;
    unordered_map<TreeNode *, int> m2;

    int maxPathSum(TreeNode *root)
    {
        vector<int> v;
        _maxPathSum(root, v);

        return *max_element(v.begin(), v.end());
    }

    void _maxPathSum(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            v.push_back(helper(root));
            _maxPathSum(root->left, v);
            _maxPathSum(root->right, v);
        }
    }

    int helper(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        auto iter = m1.find(root);
        if (iter != m1.end())
        {
            return iter->second;
        }

        int val = root->val + max(0, _helper(root->left)) + max(0, _helper(root->right));

        cout << "m1 ==> " << root->val << ": " << val << endl;
        m1[root] = val;
        return val;
    }

    int _helper(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        auto iter = m2.find(root);
        if (iter != m2.end())
        {
            return iter->second;
        }

        int val = root->val + max(0, max(_helper(root->left), _helper(root->right)));

        cout << "m2 ==> " << root->val << ": " << val << endl;
        m2[root] = val;
        return val;
    }
};

int main()
{
    TreeNode *root = new TreeNode{
        -10,
        new TreeNode{9},
        new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};

    root = new TreeNode{
        1,
        new TreeNode{-2, new TreeNode{1, new TreeNode{-1}, nullptr}, new TreeNode{3}},
        new TreeNode{-2, new TreeNode{-2}, nullptr}};

    cout << Solution().maxPathSum(root) << endl;

    cout << "done!" << endl;
    return 0;
}
