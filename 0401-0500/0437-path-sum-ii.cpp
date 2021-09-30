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
using LL = long long;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        // 前缀和
        unordered_map<int, int> cnts;
        cnts[0] = 1;
        int ans = 0;
        go(root, targetSum, 0, cnts, ans);
        return ans;
    }
    void go(TreeNode *root, LL targetSum, LL preSum, unordered_map<int, int> &cnts, int &ans) {
        preSum += root->val;
        ans += cnts[preSum - targetSum];
        ++cnts[preSum];
        if (root->left) {
            go(root->left, targetSum, preSum, cnts, ans);
        }
        if (root->right){
            go(root->right, targetSum, preSum, cnts, ans);
        }
        if (--cnts[preSum] == 0) cnts.erase(preSum);
    }
};
