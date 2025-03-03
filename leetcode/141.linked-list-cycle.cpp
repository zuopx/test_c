/*141. 环形链表

https://leetcode.cn/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }

        ListNode *p1 = head, *p2 = head->next;
        while (p1 && p2)
        {
            if (p1 == p2 or p2->next == p1)
            {
                return true;
            }
            if (!p2->next)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return false;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
