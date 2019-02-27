#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root) return {};
      vector<int> res;
      stack<TreeNode*> st;
      push_left(root, st);
      while (!st.empty()) {
        TreeNode* r = st.top();
        st.pop();
        res.push_back(r->val);
        if (r->right)
          push_left(r->right, st);
      }
      return res;
    }
private:
    void push_left(TreeNode* node, stack<TreeNode*> &st) {
      while(node) {
        st.push(node);
        node = node->left;
      }
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  root->right = n2;
  n2->left = n3;
  Solution so;
  vector<int> vs = so.inorderTraversal(root);
  PRINT_ARRAY(vs);
  return 0;
}
