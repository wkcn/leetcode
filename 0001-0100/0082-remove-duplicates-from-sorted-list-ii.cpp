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
      ListNode dummy(-1); dummy.next = head;
      ListNode *left = &dummy;
      // D -> 1 -> 1 -> 2 -> 2 -> 3
      while (left) {
        if (left->next && left->next->next && left->next->val == left->next->next->val) {
          ListNode *right = left->next->next;
          while (right->next && right->next->val == left->next->val) right = right->next;
          left->next = right->next;
        } else {
          left = left->next;
        }
      }
      return dummy.next;
    }
};

int main() {
  ListNode *li = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().deleteDuplicates(li));
  return 0;
}
