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
        deque<TreeNode*> q; q.push_back(root);
        vector<vector<int>> ans;
        bool rev = false;
        while (!q.empty()) {
            int qs = q.size();
            vector<int> vs;
            while (qs-- > 0) {
                if (rev) {
                    TreeNode *r = q.back(); q.pop_back();
                    vs.push_back(r->val);
                    if (r->right) q.push_front(r->right);
                    if (r->left) q.push_front(r->left);
                } else {
                    TreeNode *r = q.front(); q.pop_front();
                    vs.push_back(r->val);
                    if (r->left) q.push_back(r->left);
                    if (r->right) q.push_back(r->right);
                }
            }
            ans.emplace_back(move(vs));
            rev = !rev;
        }
        return ans;
    }
};
