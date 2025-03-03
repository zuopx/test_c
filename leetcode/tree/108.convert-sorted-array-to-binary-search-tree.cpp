/*108. 将有序数组转换为二叉搜索树

https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-100-liked
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *_sortedArrayToBST(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }

        if (begin == end)
        {
            return new TreeNode{nums[begin]};
        }

        int mid = (begin + end) / 2;
        TreeNode *node = new TreeNode{nums[mid]};
        node->left = _sortedArrayToBST(nums, begin, mid - 1);
        node->right = _sortedArrayToBST(nums, mid + 1, end);

        return node;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
