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
    int findSecondMinimumValue(TreeNode* root) {
        // 最小的肯定是根节点，看最小值的子节点数
        if (!root) return -1;
        int mi = root->val;
        int ans = -1;
        queue<TreeNode*> q; q.push(root);
        auto go = [&](TreeNode *r) {
            if (!r) return;
            if (r->val == mi) {
                q.push(r);
            } else {
                if (ans == -1) {
                    ans = r->val;
                } else
                    ans = min(ans, r->val);
            }
        };
        while (!q.empty()) {
            TreeNode *r = q.front(); q.pop();
            go(r->left);
            go(r->right);
        }
        return ans;
    }
};
