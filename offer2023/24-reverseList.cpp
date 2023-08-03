/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *last = nullptr, *p = head;
        while (p) {
            ListNode *old = p->next;
            p->next = last;
            last = p;
            p = old;
        }
        return last;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *r = reverseList(head->next);
        head->next->next = head;  // head->next may be nullptr
        head->next = nullptr;
        return r;
    }
};
