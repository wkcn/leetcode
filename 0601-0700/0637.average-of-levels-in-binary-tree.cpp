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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            const int size = q.size();
            double su = 0;  // 注意类型, double能表示的范围更广
            for (int i = 0; i < size; ++i) {
                TreeNode *r = q.front(); q.pop();
                su += r->val;
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            out.push_back(su / size);
        }
        return out;
    }
};
