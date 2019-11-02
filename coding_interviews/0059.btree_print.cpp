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
      queue<TreeNode*> q;
      q.push(pRoot);
      while (!q.empty()) {
        const int count = q.size();
        vector<int> v(count);
        for (int i = 0; i < count; ++i) {
          TreeNode *r = q.front(); q.pop();
          if (r->left) q.push(r->left);
          if (r->right) q.push(r->right);
          v[i] = r->val;
        }
        res.emplace_back(v);
      }
      return res;
    }
};

int main() {
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  for (vector<int> &v : Solution().Print(root)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
