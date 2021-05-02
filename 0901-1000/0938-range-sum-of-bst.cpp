class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int su = root->val >= low && root->val <= high ? root->val : 0;
        su += rangeSumBST(root->left, low, high);
        su += rangeSumBST(root->right, low, high);
        return su;
    }
};
