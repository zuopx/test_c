/*24. 两两交换链表中的节点

https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include "../mystl/list.h"
#include <gtest/gtest.h>

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *top = new ListNode(0, head);
        ListNode *parent = top;
        ListNode *left = parent->next, *right = parent->next->next;

        while (left && right)
        {
            parent->next = right;
            left->next = right->next;
            right->next = left;

            left = parent->next;
            right = parent->next->next;

            parent = parent->next->next;
            left = left->next->next;
            right = right->next ? right->next->next : right->next;
        }

        return top->next;
    }
};

ListNode *swapPairs(ListNode *head)
{
    return Solution().swapPairs(head);
}

// Test case 1: Empty list
TEST(SwapPairsTest, EmptyList)
{
    ListNode *head = nullptr;
    ListNode *result = swapPairs(head);
    EXPECT_EQ(result, nullptr);
}

// Test case 2: Single node
TEST(SwapPairsTest, SingleNode)
{
    ListNode *head = my::createList<int>({1});
    ListNode *result = swapPairs(head);

    ListNode *expected = my::createList<int>({1});
    EXPECT_TRUE(my::listsEqual(result, expected));

    my::deleteList(result);
    my::deleteList(expected);
}
// Test case 3: Two nodes
TEST(SwapPairsTest, TwoNodes)
{
    ListNode *head = my::createList<int>({1, 2});
    ListNode *result = swapPairs(head);

    ListNode *expected = my::createList<int>({2, 1});
    EXPECT_TRUE(my::listsEqual(result, expected));

    my::deleteList(result);
    my::deleteList(expected);
}

// Test case 4: Odd number of nodes
TEST(SwapPairsTest, OddNumberOfNodes)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *result = swapPairs(head);

    ListNode *expected = my::createList<int>({2, 1, 4, 3, 5});
    EXPECT_TRUE(my::listsEqual(result, expected));

    my::deleteList(result);
    my::deleteList(expected);
}

// Test case 5: Even number of nodes
TEST(SwapPairsTest, EvenNumberOfNodes)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4});
    ListNode *result = swapPairs(head);

    ListNode *expected = my::createList<int>({2, 1, 4, 3});
    EXPECT_TRUE(my::listsEqual(result, expected));

    my::deleteList(result);
    my::deleteList(expected);
}

// Test case 6: Multiple nodes
TEST(SwapPairsTest, MultipleNodes)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4, 5, 6});
    ListNode *result = swapPairs(head);

    ListNode *expected = my::createList<int>({2, 1, 4, 3, 6, 5});
    EXPECT_TRUE(my::listsEqual(result, expected));

    my::deleteList(result);
    my::deleteList(expected);
}