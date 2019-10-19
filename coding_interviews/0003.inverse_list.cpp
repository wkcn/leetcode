#include "common.h"

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {
  }
};

#if 0

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> v;
      while (head) {
        v.push_back(head->val);
        head = head->next;
      }
      // reverse
      std::reverse(v.begin(), v.end());
      return v;
    }
};

#else

#if 0

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      if (!head) return {};
      vector<int> v;
      // reverse link
      ListNode* last = nullptr;
      while (head) {
        ListNode* next = head->next;
        head->next = last;
        last = head;
        head = next;
      }
      head = last;
      while (head) {
        v.push_back(head->val);
        head = head->next;
      }
      return v;
    }
};

#else

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> v;
      tail_to_head(head, v);
      return v;
    }
private:
    void tail_to_head(ListNode* head, vector<int> &v) {
      if (!head) return;
      tail_to_head(head->next, v);
      v.push_back(head->val);
    }
};

#endif

#endif

int main() {
  ListNode* head = INPUT_LIST<ListNode>();
  vector<int> v = Solution().printListFromTailToHead(head);
  PRINT_ARRAY(v);
  return 0;
}
