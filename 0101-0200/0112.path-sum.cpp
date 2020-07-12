// 要注意减的是哪一个节点
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false; // 因为没有叶节点
        stack<pair<TreeNode*, int> > st;
        st.push({root, sum - root->val});
        while (!st.empty()) {
            auto [r, v] = st.top(); st.pop();
            if (r->left) st.push({r->left, v - r->left->val});
            if (r->right) st.push({r->right, v - r->right->val});
            if (!(r->left) && !(r->right) && v == 0) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false; // 因为没有叶节点
        stack<pair<TreeNode*, int> > st;
        st.push({root, sum});
        while (!st.empty()) {
            auto [r, v] = st.top(); st.pop();
            v -= r->val;
            if (r->left) st.push({r->left, v});
            if (r->right) st.push({r->right, v});
            if (!(r->left) && !(r->right) && v == 0) return true;
        }
        return false;
    }
};
