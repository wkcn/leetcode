class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q; q.push(root);
        int h = 0;
        while (!q.empty()) {
            ++h;
            int size = q.size();
            while (size--) {
                TreeNode *r = q.front(); q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
        }
        return h;
    }
};
