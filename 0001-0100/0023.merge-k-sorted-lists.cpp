#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct CMP_LIST {
  bool operator()(const ListNode *a, const ListNode *b) {
    return a->val >= b->val;
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, CMP_LIST> q;
      for (ListNode* li : lists) {
        if (li) q.push(li);
      }
      ListNode dummy(-1);
      ListNode *p = &dummy;
      while (!q.empty()) {
        ListNode *r = q.top(); q.pop();
        p->next = r;
        p = r;
        if (r->next) q.push(r->next);
      }
      p->next = nullptr;
      return dummy.next;
    }
};

int main() {
  vector<ListNode*> lists;
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    ListNode *li = INPUT_LIST<ListNode>();
    lists.push_back(li);
  }
  PRINT_LIST(Solution().mergeKLists(lists));
  return 0;
}
