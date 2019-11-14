#include "common.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

#define SOLUTION 3

#if SOLUTION == 0 
class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == NULL) return NULL;
    // add copied node
    RandomListNode* p = pHead;
    while (p) {
      RandomListNode* new_node = new RandomListNode(p->label);
      new_node->next = p->next;
      p->next = new_node;
      p = new_node->next;
    }
    // add random link
    p = pHead;
    while (p) {
      if (p->random)
        p->next->random = p->random->next;
      p = p->next->next;
    }
    // detach
    p = pHead;
    RandomListNode* new_head = pHead->next;
    while (p) {
      // p -> p' -> p_next -> p_next'
      RandomListNode* next = p->next->next; // may be empty
      p->next->next = next ? next->next : nullptr; // p' -> p_nextt'
      p->next = next;
      p = next;
    }
    return new_head;
  }
};
#elif SOLUTION == 1

class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead) {
    map<RandomListNode*, RandomListNode*> done;
    queue<pair<RandomListNode*, RandomListNode**> > todo;
    done[nullptr] = nullptr;
    RandomListNode* new_head;
    todo.push({pHead, {&new_head}});
    while (!todo.empty()) {
      auto p = todo.front(); todo.pop();
      RandomListNode* cur = p.first;
      RandomListNode** need = p.second;
      if (done.count(cur)) {
        *need = done[cur];
      } else {
        RandomListNode* cl = new RandomListNode(cur->label);
        done[cur] = cl;
        todo.push({cur->next, &(cl->next)});
        todo.push({cur->random, &(cl->random)});
        todo.push(p);
      }
    }
    return new_head;
  }
};

#elif SOLUTION == 3

class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead) {
    if (!pHead) return nullptr;
    RandomListNode *r = pHead;
    vector<RandomListNode*> vs;
    map<RandomListNode*, int> r2id;
    while (r) {
      r2id[r] = vs.size();
      vs.push_back(new RandomListNode(r->label));
      r = r->next;
    }
    for (int i = 0; i < vs.size() - 1; ++i) vs[i]->next = vs[i+1];
    r = pHead;
    while (r) {
      if (r->random) vs[r2id[r]]->random = vs[r2id[r->random]];
      r = r->next;
    }
    return vs[0];
  }
};

#else

class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead) {
    if (!pHead) return nullptr;
    map<RandomListNode*, RandomListNode*> ma;
    for (RandomListNode *r = pHead; r; r = r->next) {
      ma[r] = new RandomListNode(r->label);
    }
    for (RandomListNode *r = pHead; r; r = r->next) {
      ma[r]->next = ma[r->next];
      ma[r]->random = ma[r->random];
    }
    return ma[pHead];
  }
};

#endif

void PrintListRandom(RandomListNode* p) {
  while(p) {
    cout << p->random->label << ", ";
    p = p->next;
  }
  cout << endl;
}

int main() {
  vector<int> next;
  INPUT_ARRAY(next);
  vector<RandomListNode*> lst;
  for (int i = 0; i < next.size(); ++i) {
    lst.push_back(new RandomListNode(i));
  }
  for (int i = 0; i < next.size(); ++i) {
    int u = next[i];
    if (u >= 0)
      lst[i]->random = lst[u];
  }
  for (int i = 0; i < next.size() - 1; ++i) {
    lst[i]->next = lst[i+1];
  }
  RandomListNode* head = lst[0];
  PrintListRandom(head);
  RandomListNode* new_r = Solution().Clone(head);
  PrintListRandom(new_r);
  return 0;
}
