// TODO: 迭代的方法
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // LVR
        // LRV
        unordered_map<int, int> v2i;
        for (int i = 0; i < inorder.size(); ++i) {
            v2i[inorder[i]] = i;
        }
        function<TreeNode*(int,int,int,int)> F = [&](int i, int j, int b, int e) -> TreeNode* {
            if (i >= j) return nullptr;
            int v = postorder[e - 1];
            int vi = v2i[v];
            TreeNode *r = new TreeNode(v);
            int llen = vi - i;
            r->left = F(i, vi, b, b + llen);
            r->right = F(vi + 1, j, b + llen, e - 1);
            return r;
        };
        return F(0, inorder.size(), 0, postorder.size());
    }
};
