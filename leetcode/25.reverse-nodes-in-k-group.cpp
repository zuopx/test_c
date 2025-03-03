/*25. K 个一组翻转链表

https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *top = new ListNode(0, head);
        ListNode *parent = top;

        stack<ListNode *> st;
        ListNode *tmp;
        while (head)
        {
            st.push(head);
            if (st.size() == k)
            {
                tmp = head->next;
                while (!st.empty())
                {
                    parent->next = st.top();
                    st.pop();
                    parent = parent->next;
                }
                head = tmp;
                parent->next = head;
            }
            else
            {
                head = head->next;
            }
        }

        return top->next;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
