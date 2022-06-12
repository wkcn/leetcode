#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// return cur
// next = cur->right
TreeNode* GetNext(TreeNode *r) {
  if (!r) return nullptr;
  // LVR
  if (!r->left) {
    return r;
  }
  // 如果真的要到下一个节点，才会调用这个函数
  // 因为这些函数会改变状态
  while (r->left) {
    TreeNode *t = r->left;
    while (t->right && t->right != r) t = t->right;
    if (t->right == r) {
      t->right = nullptr;
      return r;
    }
    t->right = r;
    r = r->left;
  }
  // r is the leftest
  return r;
}

class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> ans;
    // 避免重复改变tree的状态
    TreeNode *r1 = nullptr, *r2 = nullptr;
    while (root1 || root2) {
      if (!r1) r1 = GetNext(root1);
      if (!r2) r2 = GetNext(root2);
      if (!r2 || (r1 && r1->val <= r2->val)) {
        ans.push_back(r1->val);
        root1 = r1->right;
        r1 = nullptr;
      } else {
        ans.push_back(r2->val);
        root2 = r2->right;
        r2 = nullptr;
      }
    }
    return ans;
  }
};

int main() {
  TreeNode *r1 = INPUT_BTREE_LEVEL<TreeNode>();
  TreeNode *r2 = INPUT_BTREE_LEVEL<TreeNode>();
  PRINT_ARRAY(Solution().getAllElements(r1, r2));
  return 0;
}
