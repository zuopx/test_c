/*160. 相交链表

https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA{0}, lenB{0}, diff; // 务必初始化
        ListNode *start, *longger, *shorter;

        start = headA;
        while (start)
        {
            ++lenA;
            start = start->next;
        }
        start = headB;
        while (start)
        {
            ++lenB;
            start = start->next;
        }

        cout << lenA << "," << lenB << endl;

        if (lenA >= lenB)
        {
            longger = headA;
            shorter = headB;
            diff = lenA - lenB;
        }
        else
        {
            longger = headB;
            shorter = headA;
            diff = lenB - lenA;
        }
        for (int i = 0; i < diff; ++i)
        {
            longger = longger->next;
        }

        cout << longger->val << "," << shorter->val << endl;

        while (longger && shorter && longger != shorter)
        {
            longger = longger->next;
            shorter = shorter->next;
        }

        return longger;
    }
};

int main()
{
    ListNode *c1 = new ListNode{8};
    ListNode *c2 = new ListNode{4};
    ListNode *c3 = new ListNode{5};
    c1->next = c2;
    c2->next = c3;

    ListNode *a1 = new ListNode{4};
    ListNode *a2 = new ListNode{1};
    a1->next = a2;
    a2->next = c1;

    ListNode *b1 = new ListNode{5};
    ListNode *b2 = new ListNode{6};
    ListNode *b3 = new ListNode{1};
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    ListNode *r = Solution().getIntersectionNode(a1, b1);
    if (r)
    {
        cout << r->val << endl;
    }
    else
    {
        cout << "null" << endl;
    }

    cout << "done!" << endl;
    return 0;
}
