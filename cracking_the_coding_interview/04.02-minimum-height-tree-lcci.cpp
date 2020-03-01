/*
 * 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
 */

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
        queue<Info> q;
        TreeNode *root = nullptr;
        q.push({0, nums.size(), &root});
        while (!q.empty()) {
            Info info = q.front(); q.pop();
            if (info.end - info.start <= 0) continue;
            int mid = info.start + ((info.end - info.start) >> 1);
            TreeNode *r = new TreeNode(nums[mid]);
            q.push({info.start, mid, &(r->left)});
            q.push({mid+1, info.end, &(r->right)});
            *(info.p) = r;
        }
        return root;
    }
private:
    struct Info {
        int start, end;
        TreeNode **p;
    };
};
