/*19. 删除链表的倒数第 N 个结点

https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *top = new ListNode(0, head);
        ListNode *par = top;

        int len{0};
        while (head)
        {
            ++len;
            head = head->next;
        }

        head = top->next;
        for (int i = 0; i < len - n; i++)
        {
            head = head->next;
            par = par->next;
        }
        par->next = head->next;

        return top->next;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
