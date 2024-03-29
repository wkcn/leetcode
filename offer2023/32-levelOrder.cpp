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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q; q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int qs = q.size();
            vector<int> v;
            while (qs-- > 0) {
                TreeNode *r = q.front(); q.pop();
                v.push_back(r->val);
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            ans.emplace_back(move(v));
        }
        return ans;
    }
};
