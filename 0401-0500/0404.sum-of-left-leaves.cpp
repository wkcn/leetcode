class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> st;
        int ans = 0;
        PushLeft(root, st, ans);
        while (!st.empty()) {
            TreeNode *r = st.top(); st.pop();
            PushLeft(r->right, st, ans);
        }
        return ans;
    }
    void PushLeft(TreeNode* root, stack<TreeNode*> &st, int &ans) {
        int old_size = st.size();
        while (root) {
            st.push(root);
            root = root->left;
        }
        if (st.size() - old_size >= 2 && !(st.top()->right)) ans += st.top()->val;
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // root 不可能是叶子
        if (!root) return 0;
        return leaves(root->left) + sumOfLeftLeaves(root->right);
    }
    int leaves(TreeNode* root) {
        // root可能是叶子
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        return leaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// 注意操作符号的优先级
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + ((root->left && (!root->left->left && !root->left->right)) ? root->left->val : 0);
    }
};
