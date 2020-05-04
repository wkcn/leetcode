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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode *root, TreeNode *min_node, TreeNode *max_node) {
        if (!root) return true;
        if (min_node && min_node->val >= root->val) return false;
        if (max_node && max_node->val <= root->val) return false;
        return isValidBST(root->left, min_node, root) && isValidBST(root->right, root, max_node);
    }
};
