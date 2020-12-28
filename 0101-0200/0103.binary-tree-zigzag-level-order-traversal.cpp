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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int> > res;
        while (!q.empty()) {
            // left -> right
            int len = q.size();
            vector<int> buf;
            while (len-- > 0) {
                TreeNode *r = q.front(); q.pop_front();
                buf.push_back(r->val);
                if (r->left) q.push_back(r->left);
                if (r->right) q.push_back(r->right);
            }
            res.emplace_back(move(buf));
            len = q.size();
            if (len == 0) break;
            while (len-- > 0) {
                TreeNode *r = q.back(); q.pop_back();
                buf.push_back(r->val);
                if (r->right) q.push_front(r->right);
                if (r->left) q.push_front(r->left);
            }
            res.emplace_back(move(buf));
        }
        return res;
    }
};
