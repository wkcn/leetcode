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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, root->val});
        int su = 0;
        while (!q.empty()) {
            auto [r, v] = q.front(); q.pop();
            if (!r->left && !r->right) {
                su += v;
                continue;
            }
            if (r->left) {
                q.push({r->left, v * 10 + r->left->val});
            }
            if (r->right) {
                q.push({r->right, v * 10 + r->right->val});
            }
        }
        return su;
    }
};
