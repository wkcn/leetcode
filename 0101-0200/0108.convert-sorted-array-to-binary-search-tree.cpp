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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getBST(nums, 0, nums.size());
    }
    TreeNode* getBST(vector<int> &nums, int start, int end) {
        if (start >= end) return nullptr;
        int mid = start + ((end - start) >> 1);
        TreeNode *r = new TreeNode(nums[mid]);
        r->left = getBST(nums, start, mid);
        r->right = getBST(nums, mid + 1, end);
        return r;
    }
};
