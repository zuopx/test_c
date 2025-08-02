/*234. 回文链表

https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked

反转整个链表

反转后半段链表

栈
*/
#include <iostream>
#include "../mystl/list.h"
#include <gtest/gtest.h>
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *r = reverseList(head);

        while (r && head)
        {
            if (r->val != head->val)
            {
                return false;
            }
            r = r->next;
            head = head->next;
        }

        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *r = nullptr;
        while (head)
        {
            r = new ListNode{head->val, r};
            head = head->next;
        }
        return r;
    }
};

bool isPalindrome(ListNode *head)
{
    return Solution().isPalindrome(head);
}

// 辅助函数：根据vector创建链表
ListNode *createList(const std::vector<int> &vals)
{
    return my::createList(vals);
}

// 辅助函数：释放链表内存
void deleteList(ListNode *head)
{
    my::deleteList(head);
}

// Test suite for isPalindrome function
class IsPalindromeTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup code if needed
    }

    void TearDown() override
    {
        // Cleanup code if needed
    }
};

// Test case 1: Empty list should return true
// 测试用例1：空链表应该返回true
TEST_F(IsPalindromeTest, EmptyList)
{
    ListNode *head = nullptr;
    EXPECT_TRUE(isPalindrome(head));
}

// Test case 2: Single node list should return true
// 测试用例2：单节点链表应该返回true
TEST_F(IsPalindromeTest, SingleNode)
{
    ListNode *head = createList({1});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 3: Two nodes palindrome list
// 测试用例3：两节点回文链表
TEST_F(IsPalindromeTest, TwoNodesPalindrome)
{
    ListNode *head = createList({1, 1});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 4: Two nodes non-palindrome list
// 测试用例4：两节点非回文链表
TEST_F(IsPalindromeTest, TwoNodesNonPalindrome)
{
    ListNode *head = createList({1, 2});
    EXPECT_FALSE(isPalindrome(head));
    deleteList(head);
}

// Test case 5: Even length palindrome list
// 测试用例5：偶数长度回文链表
TEST_F(IsPalindromeTest, EvenLengthPalindrome)
{
    ListNode *head = createList({1, 2, 2, 1});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 6: Odd length palindrome list
// 测试用例6：奇数长度回文链表
TEST_F(IsPalindromeTest, OddLengthPalindrome)
{
    ListNode *head = createList({1, 2, 3, 2, 1});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 7: Even length non-palindrome list
// 测试用例7：偶数长度非回文链表
TEST_F(IsPalindromeTest, EvenLengthNonPalindrome)
{
    ListNode *head = createList({1, 2, 3, 4});
    EXPECT_FALSE(isPalindrome(head));
    deleteList(head);
}

// Test case 8: Odd length non-palindrome list
// 测试用例8：奇数长度非回文链表
TEST_F(IsPalindromeTest, OddLengthNonPalindrome)
{
    ListNode *head = createList({1, 2, 3, 4, 5});
    EXPECT_FALSE(isPalindrome(head));
    deleteList(head);
}

// Test case 9: All same values (palindrome)
// 测试用例9：所有值相同（回文）
TEST_F(IsPalindromeTest, AllSameValues)
{
    ListNode *head = createList({5, 5, 5, 5, 5});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 10: Large palindrome list
// 测试用例10：大回文链表
TEST_F(IsPalindromeTest, LargePalindrome)
{
    std::vector<int> vals;
    for (int i = 0; i < 1000; ++i)
    {
        vals.push_back(i % 10);
    }
    // Create palindrome: 0,1,2,...,9,9,...,2,1,0
    std::vector<int> palindrome;
    for (int i = 0; i < 10; ++i)
    {
        palindrome.push_back(i);
    }
    for (int i = 9; i >= 0; --i)
    {
        palindrome.push_back(i);
    }

    ListNode *head = createList(palindrome);
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 11: Large non-palindrome list
// 测试用例11：大非回文链表
TEST_F(IsPalindromeTest, LargeNonPalindrome)
{
    std::vector<int> vals;
    for (int i = 0; i < 1000; ++i)
    {
        vals.push_back(i);
    }

    ListNode *head = createList(vals);
    EXPECT_FALSE(isPalindrome(head));
    deleteList(head);
}

// Test case 12: Palindrome with negative numbers
// 测试用例12：包含负数的回文链表
TEST_F(IsPalindromeTest, NegativeNumbersPalindrome)
{
    ListNode *head = createList({-1, -2, -2, -1});
    EXPECT_TRUE(isPalindrome(head));
    deleteList(head);
}

// Test case 13: Mixed positive and negative numbers non-palindrome
// 测试用例13：正负数混合的非回文链表
TEST_F(IsPalindromeTest, MixedNumbersNonPalindrome)
{
    ListNode *head = createList({-1, 2, -1, 3});
    EXPECT_FALSE(isPalindrome(head));
    deleteList(head);
}
