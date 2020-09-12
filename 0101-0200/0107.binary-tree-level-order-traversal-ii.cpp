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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q; q.push(root);
        vector<vector<int> > out;
        while (!q.empty()) {
            int qsize = q.size();
            vector<int> buf;
            for (int i = 0; i < qsize; ++i) {
                TreeNode *r = q.front(); q.pop();
                buf.push_back(r->val);
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            out.emplace_back(move(buf));
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
