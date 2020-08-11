#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
      // 用这种遍历方法一定要跑完以还原所有节点
      if (!root) return;
      TreeNode *pre = nullptr;
      TreeNode *pre1 = nullptr, *pre2 = nullptr;
      while (root) {
        if (root->left) {
          TreeNode *r = root->left;
          while (r->right && r->right != root) r = r->right;
          if (!(r->right)) {
            // 第一次遇到这个节点
            // 添加额外的节点, 以供回到父节点
            r->right = root;
            root = root->left;
            continue;
          } else {
            // 当前的节点的左子树已经访问完了
            // cout << root->val << endl;
            r->right = nullptr;
          }
        }
        // 遍历到root
        if (pre && pre->val > root->val) {
          // 逆序
          if (!pre1) {
            pre1 = pre;
            // 这里不能马上return, 需要把整个树先还原!!!!!!
          }
          pre2 = root;
        }
        pre = root;
        root = root->right;
      }
      // 交换的两节点
      swap(pre1->val, pre2->val);
    }
};

bool BTreeCheck(TreeNode *r) {
  if (!r) return true;
  set<TreeNode*> vis;
  queue<TreeNode*> q;
  q.push(r);
  while (!q.empty()) {
    // 记得pop!!!
    TreeNode *u = q.front(); q.pop();
    if (vis.count(u) > 0) {
      cout << "FAIL: " << u->val << endl;
      return false;
    }
    vis.insert(u);
    if (u->left) q.push(u->left);
    if (u->right) q.push(u->right);
  }
  return true;
}

int main() {
  TreeNode* r = INPUT_BTREE_LEVEL<TreeNode>(); 
/*
15
10 5 15 0 8 13 20 2 -5 6 9 12 14 18 25
*/
  Solution().recoverTree(r);
  if (!BTreeCheck(r)) {
    cout << "CHECK FAIL" << endl;
    return -1;
  }
  PRINT_BTREE_LEVEL(r);
  return 0;
}
