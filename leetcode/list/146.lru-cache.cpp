/*146. LRU 缓存

https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked

实现 LRUCache 类：
    LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
    int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
    函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

首先，肯定要使用哈希表来存数据，这样的话，读取效率都能达到O(1)。
难点在于实现缓存，维护哈希表为固定长度。
缓存用于维护key，用一个队列，当写入key时，要把key移到队首，同时要把队列中的key移除掉，而且要以O(1)时间内实现，那么就只能用链表。
如何在O(1)时间内找到链表中的key，用哈希表。

O(1)时间内移除元素，只能是stack、queue、list, hash
O(1)时间内移除任意元素，只能是linkedlist, hash
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *left, *right;

    Node(int key, int val) : key{key}, val{val}, left{nullptr}, right{nullptr}
    {
        cout << "new node: " << key << endl;
    }
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        auto iter = m.find(key);

        if (iter == m.end())
        {
            return default_val;
        }

        Node *node = iter->second;
        move_to_tail(node);

        return node->val;
    }

    void put(int key, int value)
    {
        auto iter = m.find(key);

        if (iter == m.end())
        {
            if (m.size() == capacity)
            {
                m.erase(head->key);
                cout << "erase: " << head->key << ", add: " << key << endl;
                head->key = key;
                head->val = value;
                m[key] = head;
                move_to_tail(head);
            }
            else
            {
                if (!head)
                {
                    head = new Node{key, value};
                    m[key] = head;
                    tail = head;
                }
                else
                {
                    Node *node = new Node{key, value};
                    m[key] = node;
                    tail->right = node;
                    node->left = tail;
                    tail = tail->right;
                }
            }
        }
        else
        {
            iter->second->val = value;
            move_to_tail(iter->second);
        }
    }

private:
    const static int default_val = -1;
    int capacity;
    unordered_map<int, Node *> m;
    Node *head = nullptr, *tail = nullptr;

    void move_to_tail(Node *node)
    {
        if (node == tail)
        {
            return;
        }

        // cout << "move: " << node->key << endl;

        if (node == head)
        {
            head = node->right;
            head->left = nullptr;

            tail->right = node;
            node->left = tail;

            tail = node;
            tail->right = nullptr;

            return;
        }

        auto left = node->left, right = node->right;
        left->right = right;
        right->left = left;

        node->left = nullptr;
        node->right = nullptr;

        tail->right = node;
        node->left = tail;

        tail = node;
        tail->right = nullptr;
    }
};

int main()
{
    LRUCache cache{3};

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    cout << "get: " << cache.get(4) << endl;
    ;
    cout << "get: " << cache.get(3) << endl;
    ;
    cout << "get: " << cache.get(2) << endl;
    ;
    cout << "get: " << cache.get(1) << endl;
    ;
    cache.put(5, 5);
    cout << "get: " << cache.get(1) << endl;
    ;
    cout << "get: " << cache.get(2) << endl;
    ;
    cout << "get: " << cache.get(3) << endl;
    ;
    cout << "get: " << cache.get(4) << endl;
    ;
    cout << "get: " << cache.get(5) << endl;
    ;

    cout << "done!" << endl;
    return 0;
}
