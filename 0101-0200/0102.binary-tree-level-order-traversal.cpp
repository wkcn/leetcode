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
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > ans;
        while (!q.empty()) {
            int size = q.size();
            vector<int> buf;
            while (size--) {
                TreeNode *r = q.front(); q.pop();
                buf.push_back(r->val);
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            ans.emplace_back(buf);
        }
        return ans;
    }
};
