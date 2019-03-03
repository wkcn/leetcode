#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode dummy(0);
      dummy.next = head;
      ListNode *front = &dummy;
      ListNode *back = &dummy;
      for (int i = 0; i <= n; ++i) {
        front = front->next;
      }
      while (front) {
        front = front->next;
        back = back->next;
      }
      back->next = back->next->next;
      return dummy.next;
    }
};

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  int n;
  cin >> n;
  Solution so;
  PRINT_LIST(so.removeNthFromEnd(head, n));
  return 0;
}
