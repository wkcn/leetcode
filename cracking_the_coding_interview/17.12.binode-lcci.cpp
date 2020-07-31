class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        // parent -> left -> right
        pair<TreeNode*, TreeNode*> p = convertLink(root);
        return p.first;
    }
    pair<TreeNode*, TreeNode*> convertLink(TreeNode *root) {
        // 返回(首节点，最后一个节点（包含））
        if (!root) return {nullptr, nullptr};
        if (!root->left && !root->right) return {root, root};
        if (!root->left) {
            auto p_right = convertLink(root->right);
            root->right = p_right.first;
            return {root, p_right.second};
        }
        if (!root->right) {
            auto p_left = convertLink(root->left);
            p_left.second->right = root;
            root->left = nullptr;
            return {p_left.first, root};
        }
        auto p_left = convertLink(root->left);
        auto p_right = convertLink(root->right);
        p_left.second->right = root;
        root->left = nullptr;
        root->right = p_right.first;
        return {p_left.first, p_right.second};
    }
};

// 递归中序遍历
class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        // 中序遍历
        TreeNode dummy(-1);
        TreeNode *pre = &dummy;
        convert(root, pre);
        return dummy.right;
    }
    void convert(TreeNode *root, TreeNode *&pre) {
        if (!root) return;
        convert(root->left, pre);
        root->left = nullptr;
        pre->right = root;
        pre = root;
        convert(root->right, pre);
    }
};

// TODO: 迭代的方法
