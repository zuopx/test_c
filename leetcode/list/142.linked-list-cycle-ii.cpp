/*142. 环形链表 II

https://leetcode.cn/problems/linked-list-cycle-ii/description/?envType=study-plan-v2&envId=top-100-liked

同141，只是返回值不一样
*/
#include <gtest/gtest.h>
#include <set>
#include "../mystl/list.h"
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> s;
        while (head)
        {
            if (s.count(head))
            {
                return head;
            }
            s.insert(head);
            head = head->next;
        }

        return nullptr;
    }

    ListNode *detectCycle2(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break; // slow, fast是快慢指针相遇点，并非环起始点
            }
        }

        if (!fast || !fast->next)
            return nullptr;

        // 获取环起始点：将慢指针重置到链表起始点，两指针同时前进，直到相遇，即为环起始点
        // 慢指针前进1步，快指针前进2步，当它们相遇时，慢指针已经走了k步，快指针已经走了2k步，k为环的长度
        // k = 链表头到环起始点的距离 + 环起始点到慢指针的距离
        //   = 链表头到环起始点的距离 + 环起始点到快指针的距离
        //   = 快指针回到环起始点的距离 + 环起始点到快指针的距离
        // 所以，链表头到环起始点的距离 等于 快指针回到环起始点的距离
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

ListNode *detectCycle(ListNode *head)
{
    return Solution().detectCycle2(head);
}

// 测试辅助类
class DetectCycleTest : public ::testing::Test
{
protected:
    // 创建链表的辅助函数

    // 辅助函数：创建无环链表
    ListNode *createList(const std::vector<int> &values)
    {
        return my::createList<int>(values);
    }

    // 辅助函数：创建有环链表
    ListNode *createCycleList(const std::vector<int> &values, int cyclePos)
    {
        return my::createCycleList<int>(values, cyclePos);
    }

    // 辅助函数：释放链表内存（仅用于无环链表）
    void deleteList(ListNode *head)
    {
        my::deleteList(head);
    }

    // 辅助函数：释放有环链表的内存（需要特殊处理避免无限循环）
    void deleteCycleList(ListNode *head, int maxNodes = 100)
    {
        return my::deleteCycleList(head, maxNodes);
    }
};

// Test Case 1: Empty list
// 测试用例1：空链表
TEST_F(DetectCycleTest, EmptyList)
{
    ListNode *head = nullptr;
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, nullptr);
}

// Test Case 2: Single node without cycle
// 测试用例2：单节点无环
TEST_F(DetectCycleTest, SingleNodeNoCycle)
{
    ListNode *head = new ListNode(1);
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, nullptr);
    delete head;
}

// Test Case 3: Single node with self cycle
// 测试用例3：单节点自环
TEST_F(DetectCycleTest, SingleNodeSelfCycle)
{
    ListNode *head = new ListNode(1);
    head->next = head; // 创建自环
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, head);
    delete head;
}

// Test Case 4: Two nodes without cycle
// 测试用例4：两节点无环
TEST_F(DetectCycleTest, TwoNodesNoCycle)
{
    ListNode *head = createList({1, 2});
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, nullptr);
    deleteList(head);
}

// Test Case 5: Two nodes with cycle
// 测试用例5：两节点有环
TEST_F(DetectCycleTest, TwoNodesWithCycle)
{
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    head->next = node2;
    node2->next = head; // 创建环

    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, head);

    // 手动清理内存
    delete node2;
    delete head;
}

// Test Case 6: Multiple nodes without cycle
// 测试用例6：多节点无环
TEST_F(DetectCycleTest, MultipleNodesNoCycle)
{
    ListNode *head = createList({1, 2, 3, 4, 5});
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result, nullptr);
    deleteList(head);
}

// Test Case 7: Cycle starts at head
// 测试用例7：环起始于头节点
TEST_F(DetectCycleTest, CycleStartsAtHead)
{
    ListNode *head = createCycleList({1, 2, 3, 4}, 0); // 环从位置0开始
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result->val, 1);
    deleteCycleList(head);
}

// Test Case 8: Cycle starts at middle
// 测试用例8：环起始于中间节点
TEST_F(DetectCycleTest, CycleStartsAtMiddle)
{
    ListNode *head = createCycleList({1, 2, 3, 4, 5}, 2); // 环从位置2开始(值为3的节点)
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result->val, 3);
    deleteCycleList(head);
}

// Test Case 9: Large cycle
// 测试用例9：大环测试
TEST_F(DetectCycleTest, LargeCycle)
{
    std::vector<int> values(100);
    for (int i = 0; i < 100; ++i)
    {
        values[i] = i + 1;
    }
    ListNode *head = createCycleList(values, 50); // 环从位置50开始
    ListNode *result = detectCycle(head);
    EXPECT_EQ(result->val, 51); // 位置50对应的值是51
    deleteCycleList(head);
}

// Test Case 10: Cycle with one node in loop
// 测试用例10：环只有一个节点
TEST_F(DetectCycleTest, SingleNodeInLoop)
{
    ListNode *head = createList({1, 2, 3});
    ListNode *node1 = head;
    ListNode *node2 = head->next;
    ListNode *node3 = head->next->next;

    // 创建环：3->2
    node3->next = node2;

    ListNode *result = detectCycle(head);
    EXPECT_EQ(result->val, 2);
    deleteCycleList(head);
}

// Additional helper test to verify the helper functions work correctly
// 额外的辅助测试：验证辅助函数正确性
TEST_F(DetectCycleTest, HelperFunctionTest)
{
    // 测试createList函数
    ListNode *head = createList({1, 2, 3});
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->val, 1);
    EXPECT_EQ(head->next->val, 2);
    EXPECT_EQ(head->next->next->val, 3);
    EXPECT_EQ(head->next->next->next, nullptr);
    deleteList(head);
}