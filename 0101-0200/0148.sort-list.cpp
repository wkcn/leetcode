#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return my_merge_sort(head);
    }
    ListNode* my_merge_sort(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = my_merge_sort(slow->next);
        slow->next = nullptr;
        ListNode *left = my_merge_sort(head);
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) p->next = left;
        else p->next = right;
        return dummy.next;
    }
};
#elif SOLUTION == 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        int cnt = 1;
        ListNode *p = head;
        while (p->next) {
            ++cnt;
            p = p->next;
        }
        ListNode dummy(-1);
        dummy.next = head;
        for (int len = 1; len < cnt; len <<= 1) {
            p = dummy.next;
            ListNode *last = &dummy;
            while (p) {
                ListNode *l1 = get_link(p, len);
                ListNode *l2 = get_link(p, len);
                while (l1 || l2) {
                    while (l1 && (!l2 || l1->val < l2->val)) {
                        last->next = l1;
                        l1 = l1->next;
                        last = last->next;
                    }
                    while (l2 && (!l1 || l1->val >= l2->val)) {
                        last->next = l2;
                        l2 = l2->next;
                        last = last->next;
                    }
                }
            }
            last->next = nullptr;
        }
        return dummy.next;
    }
    ListNode *get_link(ListNode *&p, int len) {
        if (!p) return nullptr;
        ListNode *u = p;
        ListNode *r = p;
        for (int t = 1; t < len && r->next; ++t) {
            r = r->next;
        }
        p = r->next;
        r->next = nullptr;
        return u;
    }
};

#endif

int main() {
  ListNode *l = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().sortList(l));
  return 0;
}
