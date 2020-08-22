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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int h = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *r = q.front(); q.pop();
                if (!r->left && !r->right) {
                    return h;
                }
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            ++h;
        }
        return h;
    }
};
