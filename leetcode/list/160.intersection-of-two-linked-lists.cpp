/*160. 相交链表

https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked

哈希表：空间复杂度O(n)

先求得长度差D，然后让长的先走D步，然后一起走，值得遇到相同的节点
*/
#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include "../mystl/list.h"
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int diff = 0; // 务必初始化
        ListNode *start, *longger, *shorter;

        start = headA;
        while (start)
        {
            diff++;
            start = start->next;
        }
        start = headB;
        while (start)
        {
            diff--;
            start = start->next;
        }

        if (diff > 0)
        {
            longger = headA;
            shorter = headB;
        }
        else
        {
            longger = headB;
            shorter = headA;
            diff = -diff;
        }

        for (int i = 0; i < diff; ++i)
            longger = longger->next;

        while (longger && shorter && longger != shorter)
        {
            longger = longger->next;
            shorter = shorter->next;
        }

        return longger;
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    return Solution().getIntersectionNode(headA, headB);
}

// 测试类
class GetIntersectionNodeTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // 测试前准备
    }

    void TearDown() override
    {
        // 测试后清理
    }

    // 辅助函数：创建链表
    ListNode *createList(const std::vector<int> &values)
    {
        return my::createList<int>(values);
    }

    // 辅助函数：连接两个链表（用于创建相交链表）
    ListNode *connectLists(ListNode *list1, ListNode *list2, int intersectionIndex)
    {
        ListNode *current = list1;
        // 移动到连接点
        for (int i = 0; i < intersectionIndex && current; ++i)
        {
            current = current->next;
        }

        if (current)
        {
            current->next = list2;
        }
        return list1; // Return head of combined list
    }

    // 创建两个独立的相交链表
    struct IntersectingLists
    {
        ListNode *headA;
        ListNode *headB;
        ListNode *common;
    };

    IntersectingLists createIntersectingLists(const std::vector<int> &prefixA,
                                              const std::vector<int> &prefixB,
                                              const std::vector<int> &common)
    {
        IntersectingLists lists;
        lists.common = createList(common);
        ListNode *headA_prefix = createList(prefixA);
        ListNode *headB_prefix = createList(prefixB);

        lists.headA = connectLists(headA_prefix, lists.common, prefixA.size() - 1);
        lists.headB = connectLists(headB_prefix, lists.common, prefixB.size() - 1);

        return lists;
    }
    // 辅助函数：释放链表内存
    void deleteList(ListNode *head)
    {
        my::deleteList(head);
    }
};

/// TC001: 两个链表相交 - 正常相交情况
TEST_F(GetIntersectionNodeTest, TwoIntersectingLists)
{
    // Arrange: 创建相交链表
    // ListA: 4->1->8->4->5
    // ListB: 5->6->1->8->4->5
    // 相交节点: 8
    auto lists = createIntersectingLists({4, 1}, {5, 6, 1}, {8, 4, 5});

    // Act
    ListNode *result = getIntersectionNode(lists.headA, lists.headB);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->val, 8);

    // Cleanup - 只需要删除两个链表的前缀部分，公共部分只删除一次
    deleteList(lists.headA);
    // 删除headB直到公共部分之前
    ListNode *current = lists.headB;
    for (int i = 0; i < 3 && current && current->next != lists.common; ++i)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}

// TC002: 两个链表不相交 - 各自独立链表
TEST_F(GetIntersectionNodeTest, TwoNonIntersectingLists)
{
    // Arrange
    ListNode *headA = createList({4, 1, 8, 4, 5});
    ListNode *headB = createList({5, 6, 1, 8, 4, 5});

    // Act
    ListNode *result = getIntersectionNode(headA, headB);

    // Assert
    EXPECT_EQ(result, nullptr);

    // Cleanup
    deleteList(headA);

    deleteList(headB);
}

// TC003: 其中一个链表为空 - headA 为空
TEST_F(GetIntersectionNodeTest, FirstListIsNull)
{
    // Arrange
    ListNode *headA = nullptr;
    ListNode *headB = createList({5, 6, 1, 8, 4, 5});

    // Act
    ListNode *result = getIntersectionNode(headA, headB);

    // Assert
    EXPECT_EQ(result, nullptr);

    // Cleanup
    deleteList(headB);
}

// TC004: 其中一个链表为空 - headB 为空
TEST_F(GetIntersectionNodeTest, SecondListIsNull)
{
    // Arrange
    ListNode *headA = createList({4, 1, 8, 4, 5});
    ListNode *headB = nullptr;

    // Act
    ListNode *result = getIntersectionNode(headA, headB);

    // Assert
    EXPECT_EQ(result, nullptr);

    // Cleanup
    deleteList(headA);
}

// TC005: 两个链表都为空
TEST_F(GetIntersectionNodeTest, BothListsAreNull)
{
    // Arrange
    ListNode *headA = nullptr;
    ListNode *headB = nullptr;

    // Act
    ListNode *result = getIntersectionNode(headA, headB);

    // Assert
    EXPECT_EQ(result, nullptr);
}

// TC006: 相交节点在链表头部
TEST_F(GetIntersectionNodeTest, IntersectionAtHead)
{
    // Arrange: 两个链表完全相同
    ListNode *common = createList({1, 2, 3});

    // Act
    ListNode *result = getIntersectionNode(common, common);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->val, 1);

    // Cleanup - 只删除一次
    deleteList(common);
}

// TC007: 相交节点在链表尾部
TEST_F(GetIntersectionNodeTest, IntersectionAtTail)
{
    // Arrange
    // ListA: 1->2->3
    // ListB: 4->5->3 (same node 3)
    ListNode *intersection = new ListNode(3);
    ListNode *headA = createList({1, 2});
    ListNode *headB = createList({4, 5});

    // 连接尾部
    ListNode *currentA = headA;
    while (currentA->next)
        currentA = currentA->next;
    currentA->next = intersection;

    ListNode *currentB = headB;
    while (currentB->next)
        currentB = currentB->next;
    currentB->next = intersection;

    // Act
    ListNode *result = getIntersectionNode(headA, headB);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->val, 3);

    // Cleanup - 正确释放内存避免double free
    deleteList(headA);
    // 手动删除headB的节点直到intersection
    currentB = headB;
    while (currentB && currentB->next != intersection)
    {
        ListNode *temp = currentB;
        currentB = currentB->next;
        delete temp;
    }
}

// TC008: 两个链表长度相同且相交
TEST_F(GetIntersectionNodeTest, SameLengthIntersectingLists)
{
    // Arrange
    // ListA: 1->2->3->4
    // ListB: 5->6->3->4
    // 相交部分: 3->4
    auto lists = createIntersectingLists({1, 2}, {5, 6}, {3, 4});

    // Act
    ListNode *result = getIntersectionNode(lists.headA, lists.headB);

    // Assert
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->val, 3);

    // Cleanup
    deleteList(lists.headA);
    // 删除headB直到公共部分之前
    ListNode *current = lists.headB;
    for (int i = 0; i < 2 && current && current->next != lists.common; ++i)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}
