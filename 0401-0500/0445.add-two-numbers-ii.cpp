#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = GetLength(l1);
        int len2 = GetLength(l2);
        int delta = len1 - len2;
        // delta
        ListNode *pre = nullptr;
        ListNode *cur = nullptr;
        while (delta != 0) {
            int v;
            if (delta > 0) {
                v = l1->val;
                --delta;
                l1 = l1->next;
            } else {
                v = l2->val;
                ++delta;
                l2 = l2->next;
            }
            cur = new ListNode(v);
            cur->next = pre;
            pre = cur;
        }
        while (l1) {
            cur = new ListNode(l1->val + l2->val);
            cur->next = pre;
            pre = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *head = cur;
        int carry = 0;
        while (cur) {
            cur->val += carry;
            carry = cur->val / 10;
            cur->val %= 10;
            pre = cur;
            cur = cur->next;
        }
        if (carry > 0) {
            pre->next = new ListNode(1);
        }
        // reverse
        pre = nullptr;
        cur = head;
        while (cur) {
            ListNode *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
    int GetLength(ListNode *l) {
        int len = 0;
        while (l) {
            ++len;
            l = l->next;
        }
        return len;
    }
};

int main() {
  ListNode *l1 = INPUT_LIST<ListNode>();
  ListNode *l2 = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().addTwoNumbers(l1, l2));
  return 0;
}
