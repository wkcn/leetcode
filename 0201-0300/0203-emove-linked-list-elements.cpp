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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        ListNode *p = &dummy;
        while (head) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = nullptr;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy; dummy.next = head;
        ListNode *p = &dummy;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        ListNode *aft = removeElements(head->next, val);
        if (head->val == val) {
            return aft;
        }
        head->next = aft;
        return head;
    }
};
