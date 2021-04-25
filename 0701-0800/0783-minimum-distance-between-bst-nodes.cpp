/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        // 由于是二叉搜索树，LVR是升序
        if (!root) return 0;
        stack<TreeNode*> st;
        PushLeft(st, root);
        bool first = true;
        int last;
        int ans = INT32_MAX;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            if (first) {
                last = r->val;
                first = false;
            } else {
                // r->val >= last, 所以不需要abs
                ans = min(ans, (r->val - last));
                last = r->val;
            }
            PushLeft(st, r->right);
        }
        return ans;
    }
    void PushLeft(stack<TreeNode*> &st, TreeNode *r) {
        while (r) {
            st.push(r); r = r->left;
        }
    }
};
