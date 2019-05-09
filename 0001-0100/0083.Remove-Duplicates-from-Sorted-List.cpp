#include "common.h"
/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head) return head;
      ListNode *r = head;
      while (r->next) {
        if (r->next->val == r->val) {
          r->next = r->next->next;
        } else {
          r = r->next;
        }
      }
      return head;
    }
};

int main() {
  ListNode* r = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().deleteDuplicates(r));
  return 0;
}
