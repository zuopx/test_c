/*2.两数相加

https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *parent = new ListNode(0, l1);
        ListNode *head = parent;
        int val{0}, tmp{0};
        while (l1 && l2)
        {
            val = l1->val + l2->val + tmp;
            l1->val = val % 10;
            tmp = val / 10;
            l1 = l1->next;
            l2 = l2->next;
            parent = parent->next;
        }
        if (l2)
        {
            l1 = l2;
            parent->next = l1;
        }
        while (l1)
        {
            val = l1->val + tmp;
            l1->val = val % 10;
            tmp = val / 10;
            l1 = l1->next;
            parent = parent->next;
        }
        if (tmp)
        {
            parent->next = new ListNode(1);
        }

        return head->next;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
