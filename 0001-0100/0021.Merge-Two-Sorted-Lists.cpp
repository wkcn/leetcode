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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *head = nullptr, *tail = nullptr;
      while (l1 || l2) {
        ListNode *a;
        if (!l2 || (l1 && l1->val <= l2->val)) {
          a = l1;
          l1 = l1->next;
        }
        else if (!l1 || (l2 && l2->val <= l1->val)) {
          a = l2;
          l2 = l2->next;
        }
        if (tail) {
          tail->next = new ListNode(a->val);
          tail = tail->next;
        } else {
          head = tail = new ListNode(a->val);
        }
      }
      return head;
    }
};

ListNode* get_input_nodes(int n) {
  int v;
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ListNode* no = new ListNode(x);
    if (head == nullptr) {
      head = tail = no;
    } else {
      tail->next = no;
      tail = no;
    }
  }
  return head;
}


void print_node(ListNode* l) {
  bool first = true;
  while(l) {
    if (first) {
      first = false;
    } else {
      cout << " -> ";
    }
    cout << l->val;
    l = l->next;
  }
}


int main() {
  int n;
  cin >> n;
  ListNode* l1 = get_input_nodes(n);

  cin >> n;
  ListNode* l2 = get_input_nodes(n);
  Solution so;
  print_node(so.mergeTwoLists(l1, l2));
  return 0;
}
