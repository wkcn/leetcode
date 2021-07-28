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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);
        auto AP = [&](TreeNode *p, TreeNode *s) {
            if (s) {
                parents[s] = p;
                q.push(s);
            }
        };
        while (!q.empty()) {
            TreeNode *r = q.front(); q.pop();
            AP(r, r->left);
            AP(r, r->right);
        }
        vector<int> ans;
        unordered_set<TreeNode*> vis;
        auto QP = [&](TreeNode *r) {
            if (vis.insert(r).second) q.push(r);
        };
        QP(target);
        for (int t = 0; t < k; ++t) {
            int n = q.size();
            while (n--) {
                TreeNode *r = q.front(); q.pop();
                if (r->left) QP(r->left);
                if (r->right) QP(r->right);
                if (r != root)
                    QP(parents[r]);
            }
        }
        while (!q.empty()) {
            TreeNode *r = q.front(); q.pop();
            ans.push_back(r->val);
        }
        return ans;
    }
};
