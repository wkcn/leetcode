#include "common.h"

/**
 * Definition for singly-linked list.
 */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int su = 0;
      ListNode *fake_head = new ListNode(0);  
      ListNode *tail = fake_head;
      while (l1 != nullptr || l2 != nullptr || su > 0) {
        if (l1 != nullptr) {su += l1->val; l1 = l1->next;}
        if (l2 != nullptr) {su += l2->val; l2 = l2->next;}
        tail->next = new ListNode(su % 10);
        su /= 10;
        tail = tail->next;
      }
      ListNode *head = fake_head->next;
      if (!head) head = new ListNode(0);
      delete fake_head;
      return head;
    }
};

ListNode* get_node(int number) {
  ListNode *head = new ListNode(number % 10);
  number /= 10;
  ListNode *tail = head;
  while (number > 0) {
    tail->next = new ListNode(number % 10);
    number /= 10;
    tail = tail->next;
  }
  return head;
}

void PrintNode(ListNode *p) {
  int res = 0;
  int base = 1;
  while (p) {
    res += p->val * base;
    base *= 10;
    p = p->next;
  }
  cout << res << endl;
}

int main() {
  ListNode *a = get_node(342);
  ListNode *b = get_node(465);
  Solution so;
  ListNode *c = so.addTwoNumbers(a, b);
  PrintNode(c);
  return 0;
}
