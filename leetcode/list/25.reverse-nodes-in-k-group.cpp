/*25. K 个一组翻转链表

https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include "../mystl/list.h"
#include <gtest/gtest.h>
#include <vector>

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *top = new ListNode(0, head);
        ListNode *parent = top;

        std::vector<ListNode *> st;
        ListNode *next;
        while (head)
        {
            st.push_back(head);
            if (st.size() == k)
            {
                next = head->next;
                while (!st.empty())
                {
                    parent->next = st.back();
                    st.pop_back();
                    parent = parent->next;
                }
                parent->next = next;
                head = parent;
            }
            head = head->next;
        }

        return top->next;
    }
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    return Solution().reverseKGroup(head, k);
}

// Test Case 1: Empty list
TEST(ReverseKGroupTest, EmptyList)
{
    ListNode *result = reverseKGroup(nullptr, 2);
    EXPECT_EQ(result, nullptr);
}

// Test Case 2: Single node with k=1
TEST(ReverseKGroupTest, SingleNodeWithK1)
{
    ListNode *head = my::createList<int>({1});
    ListNode *expected = my::createList<int>({1});
    ListNode *result = reverseKGroup(head, 1);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 3: Length less than k
TEST(ReverseKGroupTest, LengthLessThanK)
{
    ListNode *head = my::createList<int>({1, 2});
    ListNode *expected = my::createList<int>({1, 2});
    ListNode *result = reverseKGroup(head, 3);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 4: Length equals k
TEST(ReverseKGroupTest, LengthEqualsK)
{
    ListNode *head = my::createList<int>({1, 2, 3});
    ListNode *expected = my::createList<int>({3, 2, 1});
    ListNode *result = reverseKGroup(head, 3);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 5: Length is multiple of k
TEST(ReverseKGroupTest, LengthIsMultipleOfK)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4});
    ListNode *expected = my::createList<int>({2, 1, 4, 3});
    ListNode *result = reverseKGroup(head, 2);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 6: Length greater than k but not multiple
TEST(ReverseKGroupTest, LengthGreaterThanKNotMultiple)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4, 5});
    ListNode *expected = my::createList<int>({2, 1, 4, 3, 5});
    ListNode *result = reverseKGroup(head, 2);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 7: Larger list
TEST(ReverseKGroupTest, LargerList)
{
    ListNode *head = my::createList<int>({1, 2, 3, 4, 5, 6});
    ListNode *expected = my::createList<int>({3, 2, 1, 6, 5, 4});
    ListNode *result = reverseKGroup(head, 3);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 8: k=1 special case
TEST(ReverseKGroupTest, KEquals1)
{
    ListNode *head = my::createList<int>({1, 2, 3});
    ListNode *expected = my::createList<int>({1, 2, 3});
    ListNode *result = reverseKGroup(head, 1);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}

// Test Case 9: k=0 edge case
TEST(ReverseKGroupTest, KEquals0)
{
    ListNode *head = my::createList<int>({1, 2, 3});
    ListNode *expected = my::createList<int>({1, 2, 3});
    ListNode *result = reverseKGroup(head, 0);
    EXPECT_TRUE(my::listsEqual<int>(result, expected));
    my::deleteList<int>(result);
    my::deleteList<int>(expected);
}