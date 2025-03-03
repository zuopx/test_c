/*146. LRU 缓存

https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked
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
    cout << "get: " << cache.get(4) << endl;;
    cout << "get: " << cache.get(3) << endl;;
    cout << "get: " << cache.get(2) << endl;;
    cout << "get: " << cache.get(1) << endl;;
    cache.put(5, 5);
    cout << "get: " << cache.get(1) << endl;;
    cout << "get: " << cache.get(2) << endl;;
    cout << "get: " << cache.get(3) << endl;;
    cout << "get: " << cache.get(4) << endl;;
    cout << "get: " << cache.get(5) << endl;;

    cout << "done!" << endl;
    return 0;
}
