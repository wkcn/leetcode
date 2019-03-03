#include "common.h"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode dummy(0);
      dummy.next = head;
      ListNode* p = &dummy;
      while (p->next && p->next->next) {
        // p -> n1 -> n2 -> n2p, swap(n1, n2)
        ListNode *n1 = p->next, *n2 = p->next->next; 
        ListNode* n2p = n2->next;
        n2->next = n1;
        n1->next = n2p;
        p->next = n2;
        p = n1;
      }
      return dummy.next;
    }
};

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().swapPairs(head));
  return 0;
}
