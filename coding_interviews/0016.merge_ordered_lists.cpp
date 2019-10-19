#include "common.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

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

int main() {
  ListNode* head1 = INPUT_LIST<ListNode>();
  ListNode* head2 = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().Merge(head1, head2));
  return 0;
}
