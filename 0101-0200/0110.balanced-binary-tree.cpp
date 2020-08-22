class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return GetHeight(root) >= 0;
    }
    int GetHeight(TreeNode *root) {
        if (!root) return 0;
        int left = GetHeight(root->left);
        int right = GetHeight(root->right);
        if (left < 0 || right < 0) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};
