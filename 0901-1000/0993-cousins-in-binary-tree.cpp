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
#define FUNC(r) { \
  if (r) { \
    if (r->val == x) xi = i; \
    else if (r->val == y) yi = i; \
    q.push(r); \
  } \
}

// 注意怎么表示父节点
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        if (x == y) return false;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            int xi = -1, yi = -1;
            for (int i = 0; i < qsize; ++i) {
                TreeNode *r = q.front(); q.pop();
                // 左右节点都得判断x和y
                FUNC(r->left);
                FUNC(r->right);
            }
            if (xi != -1 || yi != -1) {
                if (xi == -1 || yi == -1) return false;
                return xi != yi;
            }
        }
        return false;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      x_parent = y_parent = nullptr;
      go(root, x, y, 1, nullptr);
      if (!x_parent || !y_parent) return false;
      return x_parent != y_parent && x_depth == y_depth;
    }
    void go(TreeNode *r, int x, int y, int depth, TreeNode *parent) {
      if (!r) return;
      if (r->val == x) {
        x_parent = parent;
        x_depth = depth;
      }
      if (r->val == y) {
        y_parent = parent;
        y_depth = depth;
      }
      go(r->left, x, y, depth + 1, r);
      go(r->right, x, y, depth + 1, r);
    }
private:
    TreeNode *x_parent, *y_parent;
    int x_depth, y_depth;
};
#endif

int main() {
  TreeNode *r = INPUT_BTREE_LEVEL<TreeNode>();
  int x, y; cin >> x >> y;
  cout << Solution().isCousins(r, x, y) << endl;
  return 0;
}
