#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      stack<TreeNode*> st_p;
      stack<TreeNode*> st_q;
      st_p.push(p); st_q.push(q);
      // VLR
      while (!st_p.empty()) {
        TreeNode* a = st_p.top(); st_p.pop();
        TreeNode* b = st_q.top(); st_q.pop();
        if (!a && b) return false;
        if (a && !b) return false;
        if (!a && !b) continue;
        if (a->val != b->val) return false;
        st_p.push(a->right); st_p.push(a->left);
        st_q.push(b->right); st_q.push(b->left);
      }
      return true;
    }
};

int main() {
  TreeNode* ta = INPUT_BTREE_LEVEL<TreeNode>();
  TreeNode* tb = INPUT_BTREE_LEVEL<TreeNode>();
  Solution so;
  cout << so.isSameTree(ta, tb) << endl;
  return 0;
}
