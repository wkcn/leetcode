#include "common.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

#if 0
int get_len(ListNode *p) {
  int len = 0;
  while (p) {
    ++len;
    p = p->next;
  }
  return len;
}

void go(ListNode *& p, int s) {
  while(s--) p = p->next;
}

class Solution {
public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int l1 = get_len(pHead1);
    int l2 = get_len(pHead2);
    if (l1 < l2) {
      go(pHead2, l2 - l1);
    } else if (l1 > l2) {
      go(pHead1, l1 - l2);
    }
    while (pHead1 && pHead2) {
      if (pHead1 == pHead2) return pHead1;
      pHead1 = pHead1->next;
      pHead2 = pHead2->next;
    }
    return nullptr;
  }
};
#else

class Solution {
public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    ListNode *p1 = pHead1, *p2 = pHead2;
    while (p1 != p2) {
      p1 = p1 ? p1->next : pHead2;
      p2 = p2 ? p2->next : pHead1;
    }
    return p1;
  }
};

#endif

int main() {
  // 0 -> 1 -> 2 -> 3 -> 4
  // 5 -> 3 -> 4
  vector<ListNode*> vs;
  for (int i = 0; i <= 5; ++i) {
    vs.push_back(new ListNode(i));
  }
  vs[0]->next = vs[1];
  vs[1]->next = vs[2];
  vs[2]->next = vs[3];
  vs[3]->next = vs[4];
  vs[5]->next = vs[3];
  cout << Solution().FindFirstCommonNode(vs[0], vs[5]) << ", " << vs[3] << endl;
  return 0;
}
