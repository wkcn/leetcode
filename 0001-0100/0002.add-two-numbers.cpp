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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        int v = 0;
        while (l1 && l2) {
            v = l1->val + l2->val + v;
            p->next = new ListNode(v % 10);
            v /= 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *u = l1 ? l1 : l2;
        while (u) {
            v = u->val + v;
            p->next = new ListNode(v % 10);
            v /= 10;
            p = p->next;
            u = u->next;
        }
        if (v) p->next = new ListNode(1);
        return dummy.next;
    }
};
