/*208. 实现 Trie (前缀树)

https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Trie
{
private:
    array<Trie *, 26> children{};
    bool isEnd = false;

public:
    Trie()
    {
    }

    void insert(string word)
    {
        auto node = this;
        int idx;
        for (char ch : word)
        {
            idx = ch - 'a';
            if (node->children[idx] == nullptr)
            {
                node->children[idx] = new Trie{};
                cout << ch << endl;
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        auto node = this;
        int idx;
        for (char ch : word)
        {
            idx = ch - 'a';
            if (node->children[idx] == nullptr)
            {
                return false;
            }
            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        auto node = this;
        int idx;
        for (char ch : prefix)
        {
            idx = ch - 'a';
            if (node->children[idx] == nullptr)
            {
                return false;
            }
            node = node->children[idx];
        }

        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 返回 True
    cout << trie.search("app") << endl;     // 返回 False
    cout << trie.startsWith("app") << endl; // 返回 True
    trie.insert("app");
    cout << trie.search("app") << endl; // 返回 True

    cout << "done!" << endl;
    return 0;
}
