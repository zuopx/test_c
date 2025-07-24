/*23. 合并 K 个升序链表

https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-100-liked
*/
#include <algorithm>
#include <vector>
#include "mystl/list.h"
#include <gtest/gtest.h>
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> v;

        ListNode *left = nullptr, *right = nullptr;

        for (auto &head : lists)
        {
            if (head && !left)
            {
                left = head;
            }
            if (head && right)
            {
                right->next = head;
            }

            while (head)
            {
                v.push_back(head->val);

                if (!head->next)
                {
                    right = head;
                }
                head = head->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode *head = left;
        for (auto &val : v)
        {
            left->val = val;
            left = left->next;
        }

        return head;
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