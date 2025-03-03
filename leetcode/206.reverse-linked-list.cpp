/*206. 反转链表

https://leetcode.cn/problems/reverse-linked-list/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *r = nullptr;
        while (head)
        {
            r = new ListNode{head->val, r};
            head = head->next;
        }
        return r;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
