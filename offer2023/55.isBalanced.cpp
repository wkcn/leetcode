class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root).second;
    }
    pair<int, bool> check(TreeNode *r) {
        if (!r) return {0, true};
        auto pl = check(r->left);
        auto pr = check(r->right);
        if (!pl.second || !pr.second) return {0, false};
        return {max(pl.first, pr.first) + 1, abs(pl.first - pr.first) <= 1};
    }
};
