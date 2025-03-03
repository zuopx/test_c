/*142. 环形链表 II

https://leetcode.cn/problems/linked-list-cycle-ii/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <unordered_set>
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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        while (head)
        {
            if (s.count(head))
            {
                return head;
            }
            s.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
