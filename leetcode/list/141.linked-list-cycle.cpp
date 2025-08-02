/*141. 环形链表

https://leetcode.cn/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-100-liked

快慢指针：快指针一次走两步，慢指针一次走一步，如果快慢指针相遇，则说明有环。

哈希表：创建一个哈希表，将所有节点加入哈希表，如果某个节点已经存在于哈希表中，则说明有环。
*/
#include <gtest/gtest.h>
#include <vector>
#include "../mystl/list.h"
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }

        ListNode *slow = head, *fast = head->next;
        while (slow && fast)
        {
            if (slow == fast or fast->next == slow)
            {
                return true;
            }
            if (!fast->next)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

bool hasCycle(ListNode *head)
{
    return Solution().hasCycle(head);
}

// 测试类
class HasCycleTest : public ::testing::Test
{
protected:
    // 测试前的设置
    void SetUp() override
    {
        // 可以在这里初始化一些公共资源
    }

    // 测试后的清理
    void TearDown() override
    {
        // 清理所有创建的链表节点
    }

    // 辅助函数：创建无环链表
    ListNode *createNoCycleList(const std::vector<int> &values)
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

// Test Case 1: 空链表测试
// Input: nullptr
// Expected: false
TEST_F(HasCycleTest, EmptyList)
{
    EXPECT_FALSE(hasCycle(nullptr));
}

// Test Case 2: 单节点无环链表
// Input: [1]
// Expected: false
TEST_F(HasCycleTest, SingleNodeNoCycle)
{
    ListNode *head = new ListNode(1);
    EXPECT_FALSE(hasCycle(head));
    delete head;
}

// Test Case 3: 单节点自环链表
// Input: [1] -> 自己
// Expected: true
TEST_F(HasCycleTest, SingleNodeSelfCycle)
{
    ListNode *head = new ListNode(1);
    head->next = head; // 创建自环
    EXPECT_TRUE(hasCycle(head));
    delete head; // 注意：由于有环，实际使用中需要特殊处理
}

// Test Case 4: 多节点无环链表
// Input: [1,2,3,4,5]
// Expected: false
TEST_F(HasCycleTest, MultiNodeNoCycle)
{
    ListNode *head = createNoCycleList({1, 2, 3, 4, 5});
    EXPECT_FALSE(hasCycle(head));
    deleteList(head);
}

// Test Case 5: 多节点有环链表（环在中间）
// Input: [1,2,3,4,5] 其中5指向2
// Expected: true
TEST_F(HasCycleTest, MultiNodeWithCycle)
{
    ListNode *head = createCycleList({1, 2, 3, 4, 5}, 1); // 5指向索引1的节点(值为2)
    EXPECT_TRUE(hasCycle(head));
    deleteCycleList(head);
}

// Test Case 6: 两节点相互指向形成环
// Input: [1,2] 其中2指向1
// Expected: true
TEST_F(HasCycleTest, TwoNodeCycle)
{
    ListNode *head = createCycleList({1, 2}, 0); // 2指向索引0的节点(值为1)
    EXPECT_TRUE(hasCycle(head));
    deleteCycleList(head);
}

// Test Case 7: 长链表无环
// Input: [1,2,3,...,100]
// Expected: false
TEST_F(HasCycleTest, LongNoCycleList)
{
    std::vector<int> values;
    for (int i = 1; i <= 100; ++i)
    {
        values.push_back(i);
    }
    ListNode *head = createNoCycleList(values);
    EXPECT_FALSE(hasCycle(head));
    deleteList(head);
}

// Test Case 8: 长链表有环（环在末尾）
// Input: [1,2,3,...,100] 其中100指向1
// Expected: true
TEST_F(HasCycleTest, LongCycleList)
{
    std::vector<int> values;
    for (int i = 1; i <= 100; ++i)
    {
        values.push_back(i);
    }
    ListNode *head = createCycleList(values, 0); // 最后一个节点指向第一个节点
    EXPECT_TRUE(hasCycle(head));
    deleteCycleList(head);
}