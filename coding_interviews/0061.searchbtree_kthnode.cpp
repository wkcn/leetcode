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
  TreeNode* KthNode(TreeNode* pRoot, int k) {
    if (!pRoot) return nullptr;
    // LVR
    stack<TreeNode*> st;
    push_left(st, pRoot);
    while (!st.empty()) {
      TreeNode* r = st.top(); st.pop();
      if (--k == 0) return r;
      if (r->right) push_left(st, r->right);
    }
    return nullptr;
  }
private:
  void push_left(stack<TreeNode*> &st, TreeNode* r) {
    while (r) {
      st.push(r);
      r = r->left;
    }
  }
};

void BuildSearchTreeImpl(int v, TreeNode** ref) {
  if (*ref == nullptr) {
    *ref = new TreeNode(v); 
  } else {
    if (v < (*ref)->val) BuildSearchTreeImpl(v, &((*ref)->left));
    else if (v > (*ref)->val) BuildSearchTreeImpl(v, &((*ref)->right));
  }
}

TreeNode* BuildSearchTree(vector<int>& vs) {
  TreeNode* root = nullptr;
  TreeNode **ref = &root;
  for (int v : vs) {
    BuildSearchTreeImpl(v, ref);
  }
  return root;
}

int main() {
  vector<int> vs;
  INPUT_ARRAY(vs);
  TreeNode* root = BuildSearchTree(vs);
  int k;
  cin >> k;
  cout << Solution().KthNode(root, k)->val << endl;
  return 0;
}
