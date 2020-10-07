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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        TreeNode *r;
        if (!t1) r = new TreeNode(t2->val);
        else if (!t2) r = new TreeNode(t1->val);
        else r = new TreeNode(t1->val + t2->val);
        r->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        r->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return r;
    }
};
