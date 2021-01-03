#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode front(-1), back(-1);
        ListNode *f = &front, *b = &back;
        while (head) {
            if (head->val < x) {
                f->next = head;
                f = f->next;
            } else {
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }
        f->next = back.next;
        b->next = nullptr;
        return front.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int x; cin >> x;
  PRINT_LIST(Solution().partition(head, x));
  return 0;
}
