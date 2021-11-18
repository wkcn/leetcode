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
        ListNode *pre = head;
        while (k-- > 0 && pre) pre = pre->next;
        while (pre) {
            pre = pre->next;
            head = head->next;
        }
        return head;
    }
};
