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
    vector<int> reversePrint(ListNode* head) {
        int cnt = 0;
        ListNode *p = head;
        while (p) {
            ++cnt;
            p = p->next;
        }
        vector<int> res(cnt);
        p = head;
        int i = cnt;
        while (p) {
            res[--i] = p->val;
            p = p->next;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head) return {};
        auto r = reversePrint(head->next);
        r.push_back(head->val);
        return r;
    }
};
