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
    vector<int> findMode(TreeNode* root) {
        // LVR
        if (!root) return {};
        int max_count = 1;
        int cnt = 0;
        int v = 0;
        vector<int> ans;
        while (root) {
            while (root->left) {
                TreeNode *r = root->left;
                while (r->right && r->right != root) r = r->right;
                if (r->right == root) {
                    r->right = nullptr;
                    break;
                } else {
                   r->right = root;
                   root = root->left;
                }
            }
            if (cnt == 0) {
                cnt = 1;
                v = root->val;
            } else if (v != root->val) {
                if (cnt > max_count) ans.clear();
                if (cnt >= max_count) {
                    max_count = cnt;
                    ans.push_back(v);
                }
                cnt = 1;
                v = root->val;
            } else {
                ++cnt;
            }

            root = root->right;

        }
        if (cnt > max_count) ans.clear();
        if (cnt >= max_count) {
            max_count = cnt;
            ans.push_back(v);
        }
        return ans;
    }
};
