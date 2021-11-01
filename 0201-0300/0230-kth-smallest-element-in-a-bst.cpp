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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        // LVR
        stack<TreeNode*> st; push_left(st, root);
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            if (--k == 0) {
                return r->val;
            }
            push_left(st, r->right);
        }
        return 0;
    }
    void push_left(stack<TreeNode*> &st, TreeNode *r) {
        while (r) {
            st.push(r); r = r->left;
        }
    }
};
