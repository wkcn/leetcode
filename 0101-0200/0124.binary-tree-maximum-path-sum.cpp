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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int best = INT32_MIN;
        function<int(TreeNode*)> F;
        F = [&](TreeNode *r) {
            if (!r) return 0;
            int left = F(r->left);
            int right = F(r->right);
            int ma = max(left, right) + r->val;
            best = max(best, left + right + r->val);
            return max(ma, 0);
        };
        F(root);
        return best;
    }
};
