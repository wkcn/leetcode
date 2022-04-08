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
    int findTilt(TreeNode* root) {
        int ans = 0;
        tile(root, ans);
        return ans;
    }
    int tile(TreeNode *root, int &ans) {
        // return sum
        if (!root) return 0;
        int a = tile(root->left, ans);
        int b = tile(root->right, ans);
        ans += abs(a - b);
        return a + b + root->val;
    }
};
