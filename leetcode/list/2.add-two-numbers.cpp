/*2.两数相加

https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/
#include <gtest/gtest.h>
#include "../mystl/list.h"

using ListNode = my::ListNode<int>;

class Solution
{
public:
    // Original version
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *parent = new ListNode(0, l1);
        ListNode *head = parent;
        int value{0}, carry{0};
        while (l1 && l2)
        {
            value = l1->val + l2->val + carry;
            l1->val = value % 10;
            carry = value / 10;
            l1 = l1->next;
            l2 = l2->next;
            parent = parent->next;
        }
        if (l2)
        {
            l1 = l2;
            parent->next = l1;
        }
        while (l1)
        {
            value = l1->val + carry;
            l1->val = value % 10;
            carry = value / 10;
            l1 = l1->next;
            parent = parent->next;
        }
        if (carry)
        {
            parent->next = new ListNode(1);
        }

        return head->next;
    }

    // Optimized version
    // This version creates new nodes for the result, avoiding modifying l1 and l2
    // It also handles the carry more cleanly
    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;
            int sum = a + b + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        return head->next;
    }

    // Alternative implementation
    // This version avoids creating new nodes for l1 and l2, using existing nodes instead
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;
            int sum = a + b + carry;

            carry = sum / 10;
            auto newNode = l1 ? l1 : (l2 ? l2 : new ListNode(0));
            newNode->val = sum % 10;
            current->next = newNode;
            current = current->next;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        return head->next;
    }
};

// 测试用例
// 为什么使用createList函数需指定类型参数int，而使用listsEqual和deleteList时不用？
// createList 必须显式指定模板参数 <int>，因为编译器无法从 {2, 4, 3} 这样的初始化列表中自动推断出类型。
// listsEqual和deleteList 传入的是已经明确是 ListNode* 类型的指针，所以编译器已经知道它们操作的是 int 类型的链表节点，不需要再指定类型。
TEST(AddTwoNumbersTest, TC01_NoCarry)
{
    ListNode *l1 = my::createList<int>({2, 4, 3});
    ListNode *l2 = my::createList<int>({5, 6, 4});
    ListNode *expected = my::createList<int>({7, 0, 8});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(l1);
    deleteList(l2);
    deleteList(expected);
    deleteList(result);
}

TEST(AddTwoNumbersTest, TC02_WithCarry)
{
    ListNode *l1 = my::createList<int>({9, 9, 9});
    ListNode *l2 = my::createList<int>({9, 9, 9, 9});
    ListNode *expected = my::createList<int>({8, 9, 9, 0, 1});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(l1);
    deleteList(l2);
    deleteList(expected);
    deleteList(result);
}

TEST(AddTwoNumbersTest, TC03_OneEmptyList)
{
    ListNode *l1 = nullptr;
    ListNode *l2 = my::createList<int>({0});
    ListNode *expected = my::createList<int>({0});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(l2);
    deleteList(expected);
    deleteList(result);
}

TEST(AddTwoNumbersTest, TC04_CarryInMiddle)
{
    ListNode *l1 = my::createList<int>({9, 8});
    ListNode *l2 = my::createList<int>({2});
    ListNode *expected = my::createList<int>({1, 9});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(l1);
    deleteList(l2);
    deleteList(expected);
    deleteList(result);
}

TEST(AddTwoNumbersTest, TC05_BothEmpty)
{
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *expected = my::createList<int>({});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(expected);
    deleteList(result);
}

TEST(AddTwoNumbersTest, TC06_DifferentLengthWithCarry)
{
    ListNode *l1 = my::createList<int>({1});
    ListNode *l2 = my::createList<int>({9, 9});
    ListNode *expected = my::createList<int>({0, 0, 1});
    ListNode *result = Solution().addTwoNumbers1(l1, l2);
    EXPECT_TRUE(listsEqual(result, expected));
    deleteList(l1);
    deleteList(l2);
    deleteList(expected);
    deleteList(result);
}
