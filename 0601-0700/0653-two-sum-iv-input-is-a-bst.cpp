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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> se;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            if (se.count(k - r->val)) return true;
            se.insert(r->val);
            if (r->left) st.push(r->left);
            if (r->right) st.push(r->right);
        }
        return false;
    }
};
