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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode dummy; dummy.next = head;
      ListNode *p = &dummy;
      while (p->next && p->next->next) {
        if (p->next->val == p->next->next->val) {
          p->next->next = p->next->next->next;
        } else {
          p = p->next;
        }
      }
      return dummy.next;
    }
};

int main() {
  ListNode *li = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().deleteDuplicates(li));
}
