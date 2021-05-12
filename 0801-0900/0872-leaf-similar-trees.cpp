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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return LVR(root1) == LVR(root2);
    }
    vector<int> LVR(TreeNode *root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        PushLeft(st, root);
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            if (!r->left && !r->right) ans.push_back(r->val);
            PushLeft(st, r->right);
        }
        return ans;
    }
    void PushLeft(stack<TreeNode*> &st, TreeNode *r) {
        while (r) {
            st.push(r);
            r = r->left;
        }
    }
};
