/*138.随机链表的复制

https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> m;

        Node *top = new Node(0);
        Node *parent = top;
        while (head)
        {
            parent->next = new Node(head->val);
            parent->next->random = head->random;
            m[head] = parent->next;

            head = head->next;
            parent = parent->next;
        }

        head = top->next;
        while (head)
        {
            if (head->random)
            {
                head->random = m.at(head->random);
            }
            head = head->next;
        }

        return top->next;
    }
};

int main()
{
    cout << "done!" << endl;
    return 0;
}
