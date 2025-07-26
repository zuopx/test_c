/*23. 合并 K 个升序链表

https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-100-liked
*/
#include <algorithm>
#include <vector>
#include "../mystl/list.h"
#include <gtest/gtest.h>
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }

        auto mergeTwoLists = [](ListNode *l1, ListNode *l2) -> ListNode *
        {
            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;
            while (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            cur->next = l1 ? l1 : l2;
            return dummy->next;
        };

        // 每次合并列表末尾的两个链表
        // 得到的新链表插入列表开头
        // 直到列表中只剩下一个链表
        // 时间复杂度为 O(nlogk)，k 为链表个数，n为列表中链表的总长度
        while (lists.size() > 1)
        {
            auto list1 = lists.back();
            lists.pop_back();
            auto list2 = lists.back();
            lists.pop_back();
            lists.insert(lists.begin(), mergeTwoLists(list1, list2));
        }

        return lists[0];
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return Solution().mergeKLists(lists);
}

// Unit Tests
TEST(MergeKListsTest, EmptyInput)
{
    vector<ListNode *> lists;
    ListNode *result = mergeKLists(lists);
    EXPECT_EQ(result, nullptr);
}

TEST(MergeKListsTest, SingleList)
{
    vector<int> list1 = {1, 4, 5};
    vector<ListNode *> lists = {my::createList<int>(list1)};
    ListNode *result = mergeKLists(lists);
    EXPECT_TRUE(listsEqual(result, my::createList<int>(list1)));
}

TEST(MergeKListsTest, MultipleLists)
{
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};
    vector<ListNode *> lists = {my::createList<int>(l1), my::createList<int>(l2), my::createList<int>(l3)};
    ListNode *result = mergeKLists(lists);

    vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    ListNode *expectedList = my::createList<int>(expected);
    EXPECT_TRUE(listsEqual(result, expectedList));
}

TEST(MergeKListsTest, ListsWithNullptr)
{
    vector<ListNode *> lists = {nullptr, my::createList<int>({1, 2, 3}), nullptr};
    ListNode *result = mergeKLists(lists);

    vector<int> expected = {1, 2, 3};
    ListNode *expectedList = my::createList<int>(expected);
    EXPECT_TRUE(listsEqual(result, expectedList));
}

TEST(MergeKListsTest, AllNullptr)
{
    vector<ListNode *> lists = {nullptr, nullptr};
    ListNode *result = mergeKLists(lists);
    EXPECT_EQ(result, nullptr);
}