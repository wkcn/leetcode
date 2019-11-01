#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

#define SOLUTION 1

#if SOLUTION == 0
class Solution {
public:
  ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (!pHead) return nullptr;
    ListNode* slow = pHead;
    ListNode* fast = pHead;
    while (slow && fast) {
      slow = slow->next;
      fast = fast->next;
      if (!fast) return nullptr;
      fast = fast->next;
      if (slow == fast) {
        break;
      }
    }
    if (!slow || !fast) return nullptr;
    slow = pHead;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};
#else

class Solution {
public:
  ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode *slow = pHead, *fast = pHead;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;
    slow = pHead;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};

#endif

int main() {
  // 0 -> 1 -> 2 -> 3 -> 1
  vector<ListNode*> vs;
  for (int i = 0; i < 4; ++i) {
    vs.push_back(new ListNode(i));
  }
  vs[0]->next = vs[1];
  vs[1]->next = vs[2];
  vs[2]->next = vs[3];
  vs[3]->next = vs[1];
  cout << Solution().EntryNodeOfLoop(vs[0]) << ", " << vs[1] << endl;
  return 0;
}
