class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *p = head;
        int len = 0;
        while (p) {++len; p = p->next;}
        int g = len / k;
        int r = len % k;
        vector<ListNode*> ans;
        ListNode dummy(-1, head);

        for (int i = 0; i < k; ++i) {
            int a = g + (i < r);
            p = &dummy;
            ans.push_back(dummy.next);
            while (a-- > 0) {
                p = p->next;
            }
            dummy.next = p->next; p->next = nullptr;
        }
        return ans;
    }
};
