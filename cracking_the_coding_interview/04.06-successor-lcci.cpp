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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p) return nullptr;
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }
        TreeNode *last = nullptr; // 记录刚好比p->val大的节点
        TreeNode *r = root;
        while (r) {
            if (p->val == r->val) {
                break;
            }
            if (p->val < r->val) {
                last = r;
                r = r->left;
            } else {
                r = r->right;
            }
        }
        return last;
    }
};
