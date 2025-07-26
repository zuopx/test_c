/*206. 反转链表

https://leetcode.cn/problems/reverse-linked-list/?envType=study-plan-v2&envId=top-100-liked
*/

#include "../mystl/list.h"
#include <gtest/gtest.h>
#include <vector>

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr; // 为head虚构一个prev，功能类似哨兵
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseList2(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

ListNode *reverseList(ListNode *head)
{
    return Solution().reverseList2(head);
}

// Test Case 1: Empty list
TEST(ReverseListTest, EmptyList)
{
    ListNode *result = reverseList(nullptr);
    EXPECT_EQ(result, nullptr);
}

// Test Case 2: Single node list
TEST(ReverseListTest, SingleNode)
{
    ListNode *head = my::createList<int>({1});
    ListNode *expected = my::createList<int>({1});
    ListNode *result = reverseList(head);

    EXPECT_TRUE(my::listsEqual<int>(result, expected));

    my::deleteList<int>(expected);
    my::deleteList<int>(result);
}

// Test Case 3: Two node list
TEST(ReverseListTest, TwoNodes)
{
    ListNode *head = my::createList<int>({1, 2});
    ListNode *expected = my::createList<int>({2, 1});
    ListNode *result = reverseList(head);

    EXPECT_TRUE(my::listsEqual<int>(result, expected));

    my::deleteList<int>(expected);
    my::deleteList<int>(result);
}

// Test Case 4: Multiple nodes
TEST(ReverseListTest, MultipleNodes)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *expected = my::createList<int>({5, 4, 3, 2, 1});
    ListNode *result = reverseList(head);

    EXPECT_TRUE(my::listsEqual<int>(result, expected));

    my::deleteList<int>(expected);
    my::deleteList<int>(result);
}

// Test Case 5: List with duplicate values
TEST(ReverseListTest, DuplicateValues)
{
    ListNode *head = my::createList<int>({1, 2, 2, 3, 1});
    ListNode *expected = my::createList<int>({1, 3, 2, 2, 1});
    ListNode *result = reverseList(head);

    EXPECT_TRUE(my::listsEqual<int>(result, expected));

    my::deleteList<int>(expected);
    my::deleteList<int>(result);
}

// Test Case 6: List with negative values
TEST(ReverseListTest, NegativeValues)
{
    ListNode *head = my::createList<int>({-1, -2, 3, -4});
    ListNode *expected = my::createList<int>({-4, 3, -2, -1});
    ListNode *result = reverseList(head);

    EXPECT_TRUE(my::listsEqual<int>(result, expected));

    my::deleteList<int>(expected);
    my::deleteList<int>(result);
}