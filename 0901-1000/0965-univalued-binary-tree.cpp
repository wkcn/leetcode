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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q; q.push(root);
        const int v = root->val;
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t->val != v) return false;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return true;
    }
};
