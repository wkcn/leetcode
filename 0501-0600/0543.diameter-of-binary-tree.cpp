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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int best = 0;
        go(root, best);
        return best;
    }
    int go(TreeNode *root, int &best) {
        if (!root) return 0;
        int left = go(root->left, best);
        int right = go(root->right, best);
        int d = left + right;
        if (d > best) best = d;
        return max(left, right) + 1;
    }
};
