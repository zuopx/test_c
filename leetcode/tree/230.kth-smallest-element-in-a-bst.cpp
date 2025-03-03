/*230. 二叉搜索树中第 K 小的元素

https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked
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
    int kthSmallest(TreeNode *root, int k)
    {
        int val;
        helper(root, k, val);
        return val;
    }

    void helper(TreeNode *root, int &k, int &val)
    {
        if (root && k)
        {

            helper(root->left, k, val);

            if (k)
            {
                --k;
                if (!k)
                {
                    val = root->val;
                }
            }

            helper(root->right, k, val);
        }
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
