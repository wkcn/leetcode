/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 如果先加右节点能够更快
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vs;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *r = q.front(); q.pop();
                if (r->left)q.push(r->left);
                if (r->right)q.push(r->right);
                if (i == size-1)
                    vs.push_back(r->val);
            }
        }
        return vs;
    }
};
