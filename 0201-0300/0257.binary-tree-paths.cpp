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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        // DFS
        vector<string> out;
        vector<string> buf;
        dfs(root, buf, out);
        return out;
    }
    void dfs(TreeNode *root, vector<string> &buf, vector<string> &out) {
        if (!(root->left) && !(root->right)) {
            string s;
            bool first = true;
            for (string &v : buf) {
                s += v;
                s += "->";
            }
            s += to_string(root->val);
            out.emplace_back(std::move(s));
            return;
        }
        buf.emplace_back(to_string(root->val));
        if (root->left) dfs(root->left, buf, out);
        if (root->right) dfs(root->right, buf, out);
        buf.pop_back();
    }
};
