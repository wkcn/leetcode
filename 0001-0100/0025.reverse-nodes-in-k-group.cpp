#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *start = &dummy;
        while (start) { // 条件
            int i = 0;
            ListNode *end = start;
            for (i = 0; i < k && end; ++i) {
                end = end->next;
            }
            if (!end) break; // 注意这里的处理
            ListNode *next = start->next;
            reverseGroup(start, end->next);
            start = next;
        }
        return dummy.next;
    }
    void reverseGroup(ListNode *head, ListNode *tail) {
        // reverse head->next to tail
        // for example, head -> 1 -> 2 -> 3 -> tail
        // result: head -> 3 -> 2 -> 1 -> tail
        ListNode *pre = tail;
        ListNode *cur = head->next;
        while (cur != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = pre;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  int k;
  cin >> k;
  PRINT_LIST(Solution().reverseKGroup(head, k));
  return 0;
}
