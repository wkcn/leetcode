#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if (!root) return true;
      stack<pair<TreeNode*, TreeNode*> > st;
      st.push({root->left, root->right});
      while (!st.empty()) {
        auto p = st.top(); st.pop();
        TreeNode* l = p.first;
        TreeNode* r = p.second;
        if ((!l && r) || (l && !r)) return false;
        if (!l && !r) continue;
        if (l->val != r->val) return false;
        st.push({l->left, r->right});
        st.push({l->right, r->left});
      }
      return true;
    }
};

int main() {
  TreeNode* root = INPUT_BTREE_LEVEL<TreeNode>();
  Solution so;
  cout << so.isSymmetric(root) << endl;
  return 0;
}
