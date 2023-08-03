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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *r = p;
        while(--k > 0) r = r->next;
        while (r->next) {
            r = r->next;
            p = p->next;
        }
        return p;
    }
};
