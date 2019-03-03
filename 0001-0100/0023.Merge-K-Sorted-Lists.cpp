#include "common.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct greater_1 {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater_1 > q;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != 0) {
        q.push(make_pair(lists[i]->val, i));
        lists[i] = lists[i]->next;
      }
    }
    ListNode *head = nullptr, *tail = nullptr;
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      int v = p.first;
      int i = p.second;
      if (lists[i] != 0) {
        q.push(make_pair(lists[i]->val, i));
        lists[i] = lists[i]->next;
      }
      if (tail == nullptr) {
        head = tail = new ListNode(v);
      } else {
        tail->next = new ListNode(v);
        tail = tail->next;
      }
    }
    return head;
  }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *head = nullptr, *tail = nullptr;
      vector<ListNode*> lis = lists;
      while (1) {
        int best_i = -1;
        int best = 0;
        for (int i = 0; i < lis.size(); ++i) {
          if (lis[i]) {
            if (best_i == -1 || lis[i]->val < best) {
              best = lis[i]->val;
              best_i = i;
            }
          }
        }
        if (best_i == -1)break;
        lis[best_i] = lis[best_i]->next;
        if (tail) {
          tail->next = new ListNode(best);
          tail = tail->next;
        } else {
          head = tail = new ListNode(best);
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
  int k;
  cin >> k;
  vector<ListNode*> lists;
  for (int i = 0; i < k; ++i) { 
    int n;
    cin >> n;
    ListNode* li = get_input_nodes(n);
    lists.push_back(li);
  }
  Solution so;
  print_node(so.mergeKLists(lists));
  return 0;
}
