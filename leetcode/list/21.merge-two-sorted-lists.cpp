/*21. 合并两个有序链表

https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked
*/
#include "../mystl/list.h"
#include <gtest/gtest.h>

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;

        return dummy->next;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    return Solution().mergeTwoLists(list1, list2);
}

// 单元测试
TEST(MergeTwoListsTest, BothNull)
{
    EXPECT_TRUE(my::listsEqual<int>(mergeTwoLists(nullptr, nullptr), nullptr));
}

TEST(MergeTwoListsTest, FirstNull)
{
    ListNode *list2 = my::createList<int>({1, 2, 3});
    ListNode *result = mergeTwoLists(nullptr, list2);
    EXPECT_TRUE(listsEqual(result, list2));
}

TEST(MergeTwoListsTest, SecondNull)
{
    ListNode *list1 = my::createList<int>({1, 2, 3});
    ListNode *result = mergeTwoLists(list1, nullptr);
    EXPECT_TRUE(listsEqual(result, list1));
}

TEST(MergeTwoListsTest, Interleaving)
{
    ListNode *list1 = my::createList<int>({1, 3, 5});
    ListNode *list2 = my::createList<int>({2, 4, 6});
    ListNode *expected = my::createList<int>({1, 2, 3, 4, 5, 6});
    ListNode *result = mergeTwoLists(list1, list2);
    EXPECT_TRUE(listsEqual(result, expected));
}

TEST(MergeTwoListsTest, DuplicateValues)
{
    ListNode *list1 = my::createList<int>({1, 1, 1});
    ListNode *list2 = my::createList<int>({1, 1});
    ListNode *expected = my::createList<int>({1, 1, 1, 1, 1});
    ListNode *result = mergeTwoLists(list1, list2);
    EXPECT_TRUE(listsEqual(result, expected));
}

TEST(MergeTwoListsTest, ReverseOrder)
{
    ListNode *list1 = my::createList<int>({2, 4, 6});
    ListNode *list2 = my::createList<int>({1, 3, 5});
    ListNode *expected = my::createList<int>({1, 2, 3, 4, 5, 6});
    ListNode *result = mergeTwoLists(list1, list2);
    EXPECT_TRUE(listsEqual(result, expected));
}