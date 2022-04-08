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
    Solution(ListNode* head) : head_(head) {

    }
    // 水塘抽样
    int getRandom() {
        int i = 1;
        int ans = head_->val;
        ListNode *p = head_;
        while (p) {
            // 注意：是更新ans而不是退出循环
            if (rand() % (i ++) == 0) ans = p->val;
            p = p->next;
        }
        return ans;
    }
private:
    ListNode *head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
