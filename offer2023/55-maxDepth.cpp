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
        int ans = 0;
        while (!q.empty()) {
            ans += 1;
            int qsize = q.size();
            while (qsize-- > 0) {
                TreeNode *r = q.front(); q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
        }
        return ans;
    }
};
