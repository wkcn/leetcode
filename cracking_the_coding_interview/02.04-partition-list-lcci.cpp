#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *cur = &dummy;
        while (cur->next) {
          if (cur->next->val < x) {
            // 注意判断如果节点被移除又重新放回原位的情况！！！
            if (cur == p) {
              cur = cur->next;
              p = p->next;
            } else {
              // detach cur->next
              ListNode *r = cur->next;
              cur->next = r->next;
              // add node
              r->next = p->next;
              p->next = r;
              p = r;
            }
          } else cur = cur->next;
        }
        return dummy.next;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode less(-1);
      ListNode other(-1);
      ListNode *less_p = &less;
      ListNode *other_p = &other;
      ListNode *p = head;
      for (ListNode *p = head; p; p=p->next) {
        if (p->val < x) {
          less_p->next = p;
          less_p = p;
        } else {
          other_p->next = p;
          other_p = p;
        }
      }
      // 处理结尾！！！！！！！！
      other_p->next = nullptr;
      less_p->next = other.next;
      return less.next;
    }
};

#endif

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int val; cin >> val;
  PRINT_LIST(Solution().partition(head, val));
  return 0;
}
