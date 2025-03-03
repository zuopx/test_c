/*23. 合并 K 个升序链表

https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> v;

        ListNode *left = nullptr, *right = nullptr;

        for (auto &head : lists)
        {
            if (head && !left)
            {
                left = head;
            }
            if (head && right)
            {
                right->next = head;
            }

            while (head)
            {
                v.push_back(head->val);

                if (!head->next)
                {
                    right = head;
                }
                head = head->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode *head = left;
        for (auto &val : v)
        {
            left->val = val;
            left = left->next;
        }

        return head;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
