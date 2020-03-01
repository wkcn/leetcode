/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define SOLUTION 1

#if SOLUTION == 1
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p = head;
        while (p->next) {
            ListNode *r = head;
            bool dup = false;
            while (r != p->next) {
                if (r->val != p->next->val) {
                    r = r->next;
                } else {
                    p->next = p->next->next;
                    dup = true;
                    break;
                }
            }
            if (!dup) {
                p = p->next;
            }
        }
        return head;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p = head;
        while (p) {
            ListNode *r = p;
            while (r->next) {
                if (p->val == r->next->val) {
                    r->next = r->next->next;
                } else {
                    r = r->next;
                }
            }
            p = p->next;
        }
        return head;
    }
};

#endif
