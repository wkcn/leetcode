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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        // VLR
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode *r = root->left;
                while (r->right && r->right != root) r = r->right;
                if (r->right) {
                    root = root->right;
                    r->right = nullptr;
                } else {
                    r->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
