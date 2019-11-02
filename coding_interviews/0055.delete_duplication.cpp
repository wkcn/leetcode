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
  ListNode* deleteDuplication(ListNode* pHead) {
    ListNode root(-1);
    root.next = pHead;
    ListNode *pre = &root, *cur = pHead;
    // pre 当前确定不重复的节点
    // cur 工作节点
    while (cur) {
      if (cur->next && cur->val == cur->next->val) {
        while (cur->next && cur->val == cur->next->val)
          cur = cur->next;
        pre->next = cur->next;
        cur = cur->next;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    return root.next;
  }
};

int main() {
  ListNode* r = INPUT_LIST<ListNode>(); 
  PRINT_LIST(Solution().deleteDuplication(r));
  return 0;
}
