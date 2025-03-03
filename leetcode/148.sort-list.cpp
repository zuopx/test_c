/*148.排序链表

https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

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
};

/*
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    ListNode *top = new ListNode(INT32_MIN, head);

    int len{0};
    while (head) {
      ++len;
      head = head->next;
    }

    ListNode *left, *right;
    int tmp;
    for (int i = 0; i < len; ++i) {
      left = top;
      right = top->next;
      for (int j = 0; j < len - i; ++j) {
        if (left->val > right->val) {
          tmp = right->val;
          right->val = left->val;
          left->val = tmp;
        }
        left = left->next;
        right = right->next;
      }
    }

    return top->next;
  }
};
*/
int main()
{
    cout << "done!" << endl;
    return 0;
}
