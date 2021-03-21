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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // dummy -> 1 -> 2 -> 3 -> 4 -> 5
      // left = 2, right = 4
      // output: dummy -> 1 -> 4 -> 3 -> 2 -> 5
      ListNode dummy(0, head);
      ListNode *start = &dummy;
      for (int i = 1; i < left; ++i) start = start->next; // 1
      ListNode *rend = start->next; // 2
      // 从2开始反转
      int t = right - left;
      ListNode *last = rend;
      ListNode *p = last->next; 
      while (t-- > 0) {
        ListNode *next = p->next;
        p->next = last;
        last = p;
        p = next;
      }
      start->next = last;
      rend->next = p;

      return dummy.next;
    }
};

int main() {
  ListNode *p = INPUT_LIST<ListNode>(); 
  int left, right;
  cin >> left >> right;
  PRINT_LIST(Solution().reverseBetween(p, left, right));
  return 0;
}
