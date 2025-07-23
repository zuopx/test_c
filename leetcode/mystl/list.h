/*
 * This file contains a templated MyListNode structure, a templated function
 * to create a list, a templated function to compare lists, and a templated
 * function to delete a list.
 */

#include <vector>
using namespace std;

// Templated MyListNode structure
template <typename T>
struct MyListNode
{
    T val;
    MyListNode *next;
    MyListNode() : val(T()), next(nullptr) {}
    MyListNode(T x) : val(x), next(nullptr) {}
    MyListNode(T x, MyListNode *next) : val(x), next(next) {}
};

// Templated function to create a list
template <typename T>
MyListNode<T> *createList(const vector<T> &values)
{
    if (values.empty())
        return nullptr;
    MyListNode<T> *head = new MyListNode<T>(values[0]);
    MyListNode<T> *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new MyListNode<T>(values[i]);
        current = current->next;
    }
    return head;
}

// Templated function to compare lists
template <typename T>
bool listsEqual(MyListNode<T> *l1, MyListNode<T> *l2)
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
void deleteList(MyListNode<T> *head)
{
    while (head)
    {
        MyListNode<T> *next = head->next;
        delete head;
        head = next;
    }
}

// Templated function to print a list
template <typename T>
void printList(MyListNode<T> *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
