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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int v = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *r = q.front(); q.pop();
            if (r->val != v) return false;
            if (r->left) q.push(r->left);
            if (r->right) q.push(r->right);
        }
        return true;
    }
};
