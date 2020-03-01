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
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (!root) return {{}};
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> buf;
        vector<vector<int> > ans;
        Inner(q, buf, ans);
        return ans;
    }
    void Inner(deque<TreeNode*> &q, vector<int> &buf, vector<vector<int> > &ans) {
        if (q.empty()) {
            ans.push_back(buf);
            return;
        }
        int size = q.size();
        while (size--) {
            TreeNode *r = q.front(); q.pop_front();
            buf.push_back(r->val);
            int children = 0;
            if (r->left) {
                ++children;
                q.push_back(r->left);
            }
            if (r->right) {
                ++children;
                q.push_back(r->right);
            }
            Inner(q, buf, ans);
            while (children--) {
                q.pop_back();
            }
            q.push_back(r);
            buf.pop_back();
        }
    }
};
