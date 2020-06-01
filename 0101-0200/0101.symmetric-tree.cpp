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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<pair<TreeNode*, TreeNode*> > q;
        q.push({root->left, root->right});
        while (!q.empty()) {
            auto [left, right] = q.front(); q.pop();
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }
        return true;
    }
};
