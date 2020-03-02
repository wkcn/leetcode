/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 前缀和
// v[0:m] - v[0:n]
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> counts; // value -> count
        counts[0] = 1;
        return pathSum(root, sum, 0, counts);
    }
    int pathSum(TreeNode* root, int sum, int curSum, unordered_map<int, int> &counts) {
        if (!root) return 0;
        curSum += root->val;
        int cnt = 0;
        // curSum - precurSum = sum
        if (counts.find(curSum - sum) != counts.end()) {
            cnt += counts[curSum - sum];
        }
        ++counts[curSum];
        cnt += pathSum(root->left, sum, curSum, counts);
        cnt += pathSum(root->right, sum, curSum, counts);
        // recover
        if (--counts[curSum] == 0) counts.erase(curSum);
        return cnt;
    }
};
