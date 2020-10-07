/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // LVR
        stack<TreeNode*> st;
        PushLeft(st, root);
        vector<int> out;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            out.push_back(r->val);
            PushLeft(st, r->right);
        }
        return out;
    }
    void PushLeft(stack<TreeNode*> &st, TreeNode *r) {
        while (r) {
            st.push(r);
            r = r->left;
        }
    }
};
