#include "common.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

#define SOLUTION 1

#if SOLUTION == 0
class Solution {
public:
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* head = nullptr;
    ListNode** ref = &head;
    while (pHead1 && pHead2) {
      if (pHead1->val <= pHead2->val) {
        *ref = pHead1;
        pHead1 = pHead1->next;
      } else {
        *ref = pHead2;
        pHead2 = pHead2->next;
      }
      ref = &((*ref)->next);
    }
    if (pHead1) *ref = pHead1; 
    if (pHead2) *ref = pHead2; 
    return head;
  }
};
#else

class Solution {
public:
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1) return pHead2;
    if (!pHead2) return pHead1;
    ListNode *r;
    if (pHead1->val <= pHead2->val) {
      r = pHead1;
      pHead1->next = Merge(pHead1->next, pHead2);
    } else {
      r = pHead2;
      pHead2->next = Merge(pHead1, pHead2->next);
    }
    return r;
  }
};

#endif

int main() {
  ListNode* head1 = INPUT_LIST<ListNode>();
  ListNode* head2 = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().Merge(head1, head2));
  return 0;
}
