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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string lvr1 = GetLVR(t1);
        string lvr2 = GetLVR(t2);
        if (lvr1.find(lvr2) == string::npos) return false;
        string vlr1 = GetVLR(t1);
        string vlr2 = GetVLR(t2);
        if (vlr1.find(vlr2) == string::npos) return false;
        return true;
    }
    string GetLVR(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode*> st;
        PushLeft(root, st);
        string s;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            s += to_string(r->val);
            s += ',';
            PushLeft(r->right, st);
        }
        return s;
    }
    string GetVLR(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode*> st;
        st.push(root);
        string s;
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            s += to_string(r->val);
            s += ',';
            if (r->right) st.push(r->right);
            if (r->left) st.push(r->left);
        }
        return s;
    }
    void PushLeft(TreeNode *r, stack<TreeNode*> &st) {
        while (r) {
            st.push(r); r = r->left;
        }
    }
};
