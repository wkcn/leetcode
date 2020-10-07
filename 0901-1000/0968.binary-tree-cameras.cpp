// TODO: 其他方法
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
    int minCameraCover(TreeNode* root) {
        /*
        用0~3表示父节点和当前节点是否被监控
        state取值:00, 10, 11
        */
        map<pair<TreeNode*, int>, int> rec;
        return camera(root, 0b10, rec);
    }
    int camera(TreeNode *root, int state, map<pair<TreeNode*, int>, int> &rec) {
        if (!root) return 0;
        if (!root->left && !root->right) return state != 0b11;
        pair<TreeNode*, int> key{root, state};
        auto p = rec.find(key);
        if (p != rec.end()) return p->second;
        // 当父节点没被监控时, 只要其直接的子节点有一个监控即可!
        // 记得break以及记录中间状态
        int rtn = 0;
        switch(state) {
            case 0b00:
                rtn = (
                    camera(root->left, 0b11, rec) + camera(root->right, 0b11, rec) + 1
                );
                break;
            case 0b10:
                rtn = min({
                    root->left ? camera(root->left, 0b00, rec) + camera(root->right, 0b10, rec) : INT32_MAX,
                    root->right ? camera(root->left, 0b10, rec) + camera(root->right, 0b00, rec) : INT32_MAX,
                    camera(root->left, 0b11, rec) + camera(root->right, 0b11, rec) + 1
                });
                break;
            case 0b11:
                rtn = min(
                    camera(root->left, 0b10, rec) + camera(root->right, 0b10, rec),
                    camera(root->left, 0b11, rec) + camera(root->right, 0b11, rec) + 1
                );
                break;
        }
        return  (rec[key] = rtn);
    }
};
