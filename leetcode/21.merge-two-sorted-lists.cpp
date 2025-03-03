/*21. 合并两个有序链表

https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked
*/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode{0, list1};
        ListNode *parent = head;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                parent = list1;
                list1 = list1->next;
            }
            else
            {
                parent->next = list2;
                parent = list2;
                list2 = list2->next;
                parent->next = list1;
            }
        }
        if (list2)
        {
            parent->next = list2;
        }
        return head->next;
    }
};

#include <iostream>
using namespace std;

int main()
{
    cout << "done!" << endl;
    return 0;
}
