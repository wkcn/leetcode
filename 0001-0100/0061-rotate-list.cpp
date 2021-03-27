#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      int len = 0;
      ListNode *p = head;
      ListNode *last = nullptr;
      while (p) {
        ++len;
        last = p;
        p = p->next;
      }
      if (len == 0) return nullptr;
      k = len - k % len;
      if (k == len) return head;
      p = head;
      // p->next作为旋转后的开头
      for (int i = 1; i < k; ++i) {
        p = p->next;
      }
      last->next = head;
      ListNode *rtn = p->next;
      p->next = nullptr;
      return rtn;
    }
};

int main() {
  ListNode *li = INPUT_LIST<ListNode>();
  int k; cin >> k;
  PRINT_LIST(Solution().rotateRight(li, k)); 
  return 0;
}
