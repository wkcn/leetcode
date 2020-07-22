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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};  // 还是要特殊处理n == 0
        function<vector<TreeNode*>(int start, int end)> F;
        F = [&](int start, int end) {
            // [start, end)
            if (start >= end) return vector<TreeNode*>{nullptr};
            vector<TreeNode*> res;
            for (int i = start; i < end; ++i) {
                auto lefts = F(start, i);
                auto rights = F(i + 1, end);
                for (auto left : lefts) {
                    for (auto right : rights) {
                        TreeNode *r = new TreeNode(i, left, right);
                        res.push_back(r);
                    }
                }
            }
            return res;
        };
        return F(1, n + 1);
    }
};
