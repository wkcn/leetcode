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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        bool first = true;
        while (a && b) {
            if (a == b) return a;
            if (a->next) {
                a = a->next;
            } else {
                a = headB;
                if (!first) break;
                first = false;
            }
            b = b->next ? b->next : headA;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            // 这样能留一个nullptr节点，处理链表不相交的情况
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
