/*24. 两两交换链表中的节点

https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *top = new ListNode(0, head);
        ListNode *parent = top;
        ListNode *left = parent->next, *right = parent->next->next;

        while (left && right)
        {
            parent->next = right;
            left->next = right->next;
            right->next = left;

            left = parent->next;
            right = parent->next->next;

            parent = parent->next->next;
            left = left->next->next;
            right = right->next ? right->next->next : right->next;
        }

        return top->next;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
