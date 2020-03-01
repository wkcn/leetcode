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
    int kthToLast(ListNode* head, int k) {
        ListNode *fast = head;
        while (k--) fast = fast->next;
        while (fast) {
            fast = fast->next;
            head = head->next;
        }
        return head->val;
    }
};
