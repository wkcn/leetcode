class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        vector<TreeNode*> vs;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            vs.push_back(r);
            if (r->right) st.push(r->right);
            if (r->left) st.push(r->left);
        }
        for (int i = 0; i < int(vs.size()) - 1; ++i) {
            vs[i]->left = nullptr;
            vs[i]->right = vs[i + 1];
        }
        vs.back()->left = nullptr;
        vs.back()->right = nullptr;
    }
};
