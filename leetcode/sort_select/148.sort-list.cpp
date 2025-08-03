/*148.排序链表

https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked

链表排序，可以参考数组排序，差异在于，链表无法被下标索引，所以堆排序肯定不适用于链表。
合并排序将数组对半分，需要计算数组长度，所以也不太适用于链表。
快速排序和冒泡排序、选择排序，都只用到最基本的交换操作，可应用于链表。
*/
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include "../mystl/list.h"
using namespace std;

using ListNode = my::ListNode<int>;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        ListNode *tmp = head;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(), v.end());

        head = tmp;
        for (auto &num : v)
        {
            head->val = num;
            head = head->next;
        }

        head = tmp;
        return head;
    }

    // 快排排序，用于链表
    ListNode *sortList2(ListNode *head)
    {
        auto partition = [](ListNode *head, ListNode *tail) -> ListNode *
        {
            int pivot = head->val;

            ListNode *curr = head;
            while (curr != tail)
            {
                if (curr->val < pivot)
                {
                    std::swap(head->val, curr->val);
                    head = head->next;
                    std::swap(head->val, curr->val);
                }
                curr = curr->next;
            }

            head->val = pivot;

            return head;
        };

        std::function<void(ListNode *, ListNode *)> quick_sort = [&](ListNode *head, ListNode *tail)
        {
            if (head == tail)
                return;

            ListNode *mid = partition(head, tail);
            quick_sort(head, mid);
            quick_sort(mid->next, tail);
        };

        quick_sort(head, nullptr);

        return head;
    }
};

// 被测函数
ListNode *sortList(ListNode *head)
{
    return Solution().sortList2(head);
}

// 辅助函数：从vector创建链表
ListNode *createList(const std::vector<int> &vals)
{
    return my::createList(vals);
}

// 辅助函数：将链表转换为vector
std::vector<int> listToVector(ListNode *head)
{
    return my::listToVector(head);
}

// 辅助函数：释放链表内存
void deleteList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// 测试类定义
class SortListTest : public ::testing::Test
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
};

// TC001: 测试空链表
// Test empty list
TEST_F(SortListTest, EmptyList)
{
    ListNode *head = nullptr;
    ListNode *result = sortList(head);
    EXPECT_EQ(result, nullptr);
}

// TC002: 测试单节点链表
// Test single node list
TEST_F(SortListTest, SingleNode)
{
    ListNode *head = createList({1});
    ListNode *result = sortList(head);
    std::vector<int> expected = {1};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result);
}

// TC003: 测试两节点逆序链表
// Test two nodes in reverse order
TEST_F(SortListTest, TwoNodesReverse)
{
    ListNode *head = createList({2, 1});
    ListNode *result = sortList(head);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result);
}

// TC004: 测试两节点已排序链表
// Test two nodes already sorted
TEST_F(SortListTest, TwoNodesSorted)
{
    ListNode *head = createList({1, 2});
    ListNode *result = sortList(head);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result);
}

// TC005: 测试一般无序链表
// Test general unsorted list
TEST_F(SortListTest, GeneralUnsortedList)
{
    ListNode *head = createList({4, 2, 1, 3});
    ListNode *result = sortList(head);
    std::vector<int> expected = {1, 2, 3, 4};
    std::vector<int> actual = listToVector(result);
    std::sort(expected.begin(), expected.end()); // 确保期望结果正确
    EXPECT_EQ(actual, expected);
    deleteList(result);
}

// TC006: 测试包含重复元素的链表
// Test list with duplicate elements
TEST_F(SortListTest, DuplicateElements)
{
    ListNode *head = createList({1, 1, 1});
    ListNode *result = sortList(head);
    std::vector<int> expected = {1, 1, 1};
    EXPECT_EQ(listToVector(result), expected);
    deleteList(result);
}

// TC007: 测试包含负数的链表
// Test list with negative numbers
TEST_F(SortListTest, NegativeNumbers)
{
    ListNode *head = createList({-1, 5, 3, 4, 0});
    ListNode *result = sortList(head);
    std::vector<int> actual = listToVector(result);
    std::vector<int> expected = {-1, 0, 3, 4, 5};
    EXPECT_EQ(actual, expected);
    deleteList(result);
}

// TC008: 测试完全逆序的链表
// Test completely reverse ordered list
TEST_F(SortListTest, CompletelyReverseOrder)
{
    ListNode *head = createList({5, 4, 3, 2, 1});
    ListNode *result = sortList(head);
    std::vector<int> actual = listToVector(result);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(actual, expected);
    deleteList(result);
}

// 性能测试：大链表排序
// Performance test: large list sorting
TEST_F(SortListTest, LargeListPerformance)
{
    std::vector<int> largeData;
    for (int i = 1000; i >= 1; --i)
    {
        largeData.push_back(i);
    }

    ListNode *head = createList(largeData);
    ListNode *result = sortList(head);

    // 验证结果是否正确排序
    std::vector<int> actual = listToVector(result);
    std::vector<int> expected(1000);
    std::iota(expected.begin(), expected.end(), 1); // 1到1000

    EXPECT_EQ(actual, expected);
    deleteList(result);
}

// 内存泄漏测试：确保没有内存泄漏
// Memory leak test: ensure no memory leak
TEST_F(SortListTest, MemoryLeakCheck)
{
    // 这个测试主要用于配合内存检测工具
    ListNode *head = createList({3, 1, 4, 1, 5});
    ListNode *result = sortList(head);
    deleteList(result);
}
