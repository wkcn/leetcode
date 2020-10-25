#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 0 or 1
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        /*
            0(s) -> 1(f)
            0 -> 1(s) -> 2 -> null(f)
            0 -> 1(s) -> 2 -> 3(f) -> null
        */
        ListNode* right = reverse_list(slow->next);
        ListNode* left = head;
        slow->next = nullptr;
        bool success = true;
        ListNode *last = nullptr;
        while (right) {
          if (right->val != left->val) {
            success = false;
          }
          left = left->next;

          ListNode *next = right->next;
          right->next = last;
          last = right;
          right = next;
        }
        slow->next = last;
        return success;
    }
    ListNode* reverse_list(ListNode *p) {
      ListNode *last = nullptr;
      while (p) {
        ListNode *next = p->next;
        p->next = last;
        last = p;
        p = next;
      }
      return last;
    }
};

int main() {
  ListNode *lst = INPUT_LIST<ListNode>();
  cout << Solution().isPalindrome(lst) << endl; 
  PRINT_LIST(lst);
  return 0;
}
