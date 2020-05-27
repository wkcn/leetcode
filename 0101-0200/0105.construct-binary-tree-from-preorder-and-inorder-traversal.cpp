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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder: VLR
        // inorder: LVR
        function<TreeNode*(int, int, int, int)> F;
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;
        F = [&](int pstart, int pend, int istart, int iend) -> TreeNode* {
            if (pstart >= pend) return nullptr;
            int v = preorder[pstart];
            int ip = inorder_map[v];
            TreeNode *root = new TreeNode(v);
            int left = ip - istart;
            root->left = F(pstart+1, pstart+1+left, istart, ip);
            root->right = F(pstart+1+left, pend, ip+1, iend);
            return root;
        };
        return F(0, preorder.size(), 0, inorder.size());
    }
};
