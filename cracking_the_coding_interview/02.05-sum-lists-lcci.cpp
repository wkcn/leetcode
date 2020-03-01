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
        bool carry = false;
        ListNode *head = nullptr;
        ListNode **p = &head;
        while (l1 || l2) {
            int s = (l1 ? l1->val: 0) + (l2 ? l2->val: 0) + carry;
            carry = s / 10;
            *p = new ListNode(s % 10);
            p = &((*p)->next);
            // 更新链表迭代器
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        // 如果还有进位!!!!!!!!!!
        if (carry) {
            *p = new ListNode(1);
        }
        if (!head) {
            head = new ListNode(0);
        }
        return head;
    }
};
