#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode dummy;
      TreeNode *pre = &dummy;
      TreeNode *p = root;
      while (p) {
        if (p->left) {
          TreeNode *r = p->left;
          while (r->right && r->right != p) {
            r = r->right;
          }
          if (!r->right) {
            // r->right is nullptr, 说明左子树还没有访问过
            r->right = p;
            p = p->left;
            continue;
          } else {
            // 已经访问过, 可以取消链接
            r->right = nullptr;
          }
        }
        // vis(p)
        pre->left = nullptr;
        pre->right = p;
        pre = p;
        p = p->right;
      }
      if (pre) {
        pre->left = pre->right = nullptr;
      }
      return dummy.right;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode dummy;
      TreeNode *pre = &dummy;
      LVR(root, pre);
      return dummy.right;
    }
    void LVR(TreeNode *root, TreeNode *&pre) {
      // 返回最后一个节点
      if (!root) {
        return;
      }
      LVR(root->left, pre);
      // 注意下面两行的写法
      pre->right = root;
      root->left = nullptr;
      pre = root;
      LVR(root->right, pre);
    }
};

#endif

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  TreeNode *result = Solution().increasingBST(root);
  // 3 5 1 7
  PRINT_BTREE_LEVEL(result);
  return 0;
}
