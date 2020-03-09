/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 若链表为空或者只有一个结点, 直接返回
        if (!head || !(head->next)) return head;
        // head为第一个结点，head->next为从第二个结点开始的链表
        ListNode *r = reverseList(head->next);
        // r代表从第二个结点开始的链表进行反转后的第一个结点
        // head->next变为第二个结点开始的链表进行反转后的最后一个结点
        head->next->next = head;
        // head为以head开始的链表反转后最后一个结点
        head->next = nullptr;
        return r;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while (head) {
            // 记录当前处理的结点的下一个结点地址
            ListNode *next = head->next;
            // 当前处理的结点指向前一个结点
            head->next = prev;
            // 更新到下一个结点
            prev = head;
            head = next;
        }
        // 循环结束时，head为nullptr, prev为反转链表的第一个结点
        return prev;
    }
};

#endif
