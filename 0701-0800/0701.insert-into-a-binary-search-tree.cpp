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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *r = root;
        while (1) {
            if (val < r->val) {
                if (r->left) r = r->left;
                else {
                    r->left = new TreeNode(val);
                    break;
                }
            } else {
                if (r->right) r = r->right;
                else {
                    r->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
