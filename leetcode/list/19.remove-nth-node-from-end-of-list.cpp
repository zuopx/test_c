/*19. 删除链表的倒数第 N 个结点

https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <gtest/gtest.h>
#include "../mystl/list.h"
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *top = new ListNode(0, head);

        int len{0};
        while (head)
        {
            ++len;
            head = head->next;
        }

        ListNode *previous = top;
        ListNode *current = top->next;
        for (int i = 0; i < len - n; i++)
        {
            current = current->next;
            previous = previous->next;
        }
        previous->next = current->next;

        return top->next;
    }

    // 快慢指针，快指针先走n步，然后快慢指针同时开始走，当快指针到达末尾时，慢指针指向的节点就是倒数第n个节点
    ListNode *removeNthFromEnd2(ListNode *head, int n)
    {
        ListNode *top = new ListNode(0, head);
        ListNode *fast = top, *slow = top;

        while (n-- && fast)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return top->next;
    }
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    return Solution().removeNthFromEnd2(head, n);
}

// 测试用例
TEST(RemoveNthFromEndTest, SingleNodeRemoval)
{
    ListNode *input = my::createList<int>({1});
    ListNode *result = removeNthFromEnd(input, 1);
    EXPECT_TRUE(result == nullptr);
    deleteList(result);
}

TEST(RemoveNthFromEndTest, RemoveHeadNode)
{
    ListNode *input = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *result = removeNthFromEnd(input, 5);
    EXPECT_TRUE(listsEqual(result, my::createList<int>({2, 3, 4, 5})));
    deleteList(result);
}

TEST(RemoveNthFromEndTest, RemoveMiddleNode)
{
    ListNode *input = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *result = removeNthFromEnd(input, 2);
    EXPECT_TRUE(listsEqual(result, my::createList<int>({1, 2, 3, 5})));
    deleteList(result);
}

TEST(RemoveNthFromEndTest, RemoveTailNode)
{
    ListNode *input = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *result = removeNthFromEnd(input, 1);
    EXPECT_TRUE(listsEqual(result, my::createList<int>({1, 2, 3, 4})));
    deleteList(result);
}

TEST(RemoveNthFromEndTest, EmptyList)
{
    ListNode *input = nullptr;
    ListNode *result = removeNthFromEnd(input, 1);
    EXPECT_TRUE(result == nullptr);
}
