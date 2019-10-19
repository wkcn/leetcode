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
    ListNode* ReverseList(ListNode* pHead) {
      ListNode* last = nullptr;;
      ListNode* cur = pHead;
      while (cur) {
        ListNode* tmp = cur->next;
        cur->next = last;
        last = cur;
        cur = tmp;
      }
      return last;
    }
};

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().ReverseList(head));
  return 0;
}
