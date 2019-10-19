#include "common.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*
 * There are some testcases with invalid input
 * (unsigned int)0 - 1
 */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if (k == 0) return nullptr;
      ListNode* fast = pListHead;
      ListNode* slow = pListHead;
      while (k && fast) {
        fast = fast->next;
        if (k > 0) --k;
      }
      // invalid input
      if (k > 0 && !fast) return nullptr;
      while (fast) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
    }
};

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  int k;
  cin >> k;
  cout << Solution().FindKthToTail(head, k)->val << endl;
  return 0;
}
