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
  bool isSymmetrical(TreeNode* pRoot) {
    queue<pair<TreeNode*, TreeNode*> > q;
    if (!pRoot) return true;
    q.push({pRoot->left, pRoot->right});
    while (!q.empty()) {
      pair<TreeNode*, TreeNode*> p = q.front(); q.pop();
      TreeNode* pl = p.first;
      TreeNode* pr = p.second;
      if (!pl && !pr) continue;
      if (!pl || !pr) return false;
      if (pl->val != pr->val) return false;
      q.push({pl->left, pr->right});
      q.push({pl->right, pr->left});
    }
    return true;
  }
};

int main() {
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  cout << Solution().isSymmetrical(root) << endl;
  return 0;
}
