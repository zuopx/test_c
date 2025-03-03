/*98. 验证二叉搜索树

validate-binary-search-tree
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
    bool isValidBST(TreeNode *root)
    {
        vector<int> v;
        helper(root, v);

        if (v.size() == 1)
        {
            return true;
        }

        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] >= v[i + 1])
            {
                return false;
            }
        }

        return true;
    }

    void helper(TreeNode *root, vector<int> &v)
    {
        if (root)
        {
            helper(root->left, v);
            v.push_back(root->val);
            helper(root->right, v);
        }
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
