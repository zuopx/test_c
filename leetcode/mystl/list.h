/*
 * This file contains a templated ListNode structure, a templated function
 * to create a list, a templated function to compare lists, and a templated
 * function to delete a list.
 */

#include <vector>
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

}