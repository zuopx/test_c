/*138.随机链表的复制

https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-100-liked

在C++中，可以将指针作为哈希表（例如，使用 `std::unordered_map`）的键

建立一个哈希表，将原链表的节点作为键，复制的节点作为值
每次创建一个新节点，先检查哈希表，如果已经存在，则直接返回该节点，否则创建一个新的节点并添加到哈希表中
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
                // `at` 在访问不存在的键时会抛出 `std::out_of_range` 异常，而 `[]` 则会插入一个默认值。
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
