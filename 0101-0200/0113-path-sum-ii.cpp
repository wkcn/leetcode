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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> buf;
        vector<vector<int>> ans;
        go(root, targetSum, buf, ans);
        return ans;
    }
    void go(TreeNode *root, int targetSum, vector<int> &buf, vector<vector<int>> &ans) {
        if (!root) return;
        targetSum -= root->val;
        buf.push_back(root->val);
        if (targetSum == 0 && !root->left && !root->right) {
            ans.push_back(buf);
        }
        go(root->left, targetSum, buf, ans);
        go(root->right, targetSum, buf, ans);
        buf.pop_back();
    }
};
