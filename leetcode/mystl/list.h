/*
 * This file contains a templated ListNode structure, a templated function
 * to create a list, a templated function to compare lists, and a templated
 * function to delete a list.
 */

#include <vector>
#include <set>
#include <iostream>

namespace my
{

    // Templated ListNode structure
    template <typename T>
    struct ListNode
    {
        T val;
        ListNode *next;
        ListNode() : val(T()), next(nullptr) {}
        ListNode(T x) : val(x), next(nullptr) {}
        ListNode(T x, ListNode *next) : val(x), next(next) {}
    };

    // Templated function to create a list
    template <typename T>
    ListNode<T> *createList(const std::vector<T> &values)
    {
        if (values.empty())
            return nullptr;
        ListNode<T> *head = new ListNode<T>(values[0]);
        ListNode<T> *current = head;
        for (size_t i = 1; i < values.size(); ++i)
        {
            current->next = new ListNode<T>(values[i]);
            current = current->next;
        }
        return head;
    }

    // Templated function to compare lists
    template <typename T>
    bool listsEqual(ListNode<T> *l1, ListNode<T> *l2)
    {
        while (l1 && l2)
        {
            if (l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return !l1 && !l2;
    }

    // Templated function to delete a list
    template <typename T>
    void deleteList(ListNode<T> *head)
    {
        while (head)
        {
            ListNode<T> *next = head->next;
            delete head;
            head = next;
        }
    }

    // Templated function to print a list
    template <typename T>
    void printList(ListNode<T> *head)
    {
        while (head)
        {
            std::cout << head->val << " ";
            head = head->next;
        }
    }

    // 辅助函数：创建有环链表
    template <typename T>
    ListNode<T> *createCycleList(const std::vector<T> &values, int cyclePos)
    {
        if (values.empty())
        {
            return nullptr;
        }

        ListNode<T> *head = new ListNode<T>(values[0]);
        ListNode<T> *current = head;
        ListNode<T> *cycleNode = nullptr;

        // 创建链表节点
        for (size_t i = 1; i < values.size(); ++i)
        {
            current->next = new ListNode<T>(values[i]);
            current = current->next;

            // 记录环开始的节点
            if (static_cast<int>(i) == cyclePos)
            {
                cycleNode = current;
            }
        }

        // 创建环：最后一个节点指向cyclePos位置的节点
        if (cycleNode != nullptr)
        {
            current->next = cycleNode;
        }
        else if (cyclePos == 0)
        {
            // 指向头节点
            current->next = head;
        }

        return head;
    }

    // 辅助函数：释放有环链表的内存（需要特殊处理避免无限循环）
    template <typename T>
    void deleteCycleList(ListNode<T> *head, int maxNodes = 100)
    {
        if (head == nullptr)
            return;

        std::set<ListNode<T> *> visited;
        ListNode<T> *current = head;
        int count = 0;

        while (current != nullptr && count < maxNodes)
        {
            if (visited.find(current) != visited.end())
            {
                // 发现环，停止删除
                break;
            }

            visited.insert(current);
            ListNode<T> *temp = current;
            current = current->next;
            delete temp;
            count++;
        }
    }

    // 辅助函数：将链表转换为vector
    template <typename T>
    std::vector<T> listToVector(ListNode<T> *head)
    {
        std::vector<T> result;
        ListNode<T> *current = head;

        while (current)
        {
            result.push_back(current->val);
            current = current->next;
        }

        return result;
    }
}