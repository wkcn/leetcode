/*
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 */
#include "common.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
  vector<vector<int> > Print(TreeNode* pRoot) {
    if (!pRoot) return {};
    vector<vector<int> > res;
    bool flag = false;
    deque<TreeNode*> q;
    q.push_front(pRoot);
    while (!q.empty()) {
      // front - back
      const int count = q.size();
      vector<int> v(count);
      TreeNode* r;
      if (!flag) {
        for (int i = 0; i < count; ++i) {
          r = q.front(); q.pop_front();
          if (r->left) q.push_back(r->left);
          if (r->right) q.push_back(r->right);
          v[i] = r->val;
        }
      } else {
        for (int i = 0; i < count; ++i) {
          r = q.back(); q.pop_back();
          if (r->right) q.push_front(r->right);
          if (r->left) q.push_front(r->left);
          v[i] = r->val;
        }
      }
      flag = !flag;
      res.emplace_back(v);
    }
    return res;
  }
};

int main() {
  /*
   *       1
   *    2      3
   * 4    5  6   7
   *
   * 13 1 2 4 0 0 5 0 0 3 6 0 0 7
   * 1 3 2 4 5 6 7
   */
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  for (vector<int> &v : Solution().Print(root)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
