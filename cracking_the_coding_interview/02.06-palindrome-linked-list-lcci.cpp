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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        // dummy -> 1(p) -> 2(s) -> 3(f) -> null
        // dummy -> 1 -> 2(p) -> 3(s) -> 4 -> null(f)
        ListNode dummy(-1); dummy.next = head;
        ListNode *slow = head, *fast = head;
        ListNode *prev = &dummy; // 用prev的话让slow, fast指向第一个元素
        while (fast && fast->next) {
            // fast走得快，应该先更新，避免slow使链接的改变
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *left = prev, *right = fast ? slow->next : slow;
        // 更新上一个节点
        prev = slow;
        bool valid = true;
        while (right) {
            if (left->val != right->val) valid = false;
            ListNode *next = left->next;
            left->next = prev;
            prev = left;
            left = next;
            right = right->next;
        }
        return valid;
    }
};
