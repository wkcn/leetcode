#include "common.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

# if 0
class Solution {
public:
  TreeNode* Convert(TreeNode* pRootOfTree) {
    return in_convert(pRootOfTree).first;
  }
private:
  pair<TreeNode*, TreeNode*> in_convert(TreeNode* root) {
    if (!root) return {nullptr, nullptr};
    TreeNode* left = root;
    TreeNode* right = root;
    if (root->left) {
      auto p = in_convert(root->left);
      p.second->right = root;
      root->left = p.second;
      left = p.first;
    } else {
      root->left = nullptr;
    }
    if (root->right) {
      auto p = in_convert(root->right);
      p.first->left = root;
      root->right = p.first; 
      right = p.second;
    } else {
      root->right = nullptr;
    }
    return {left, right}; 
  }
};
#else

#if 0
class Solution {
public:
  TreeNode* Convert(TreeNode* pRootOfTree) {
    if (!pRootOfTree) return nullptr;
    TreeNode* pre = nullptr;
    go(pRootOfTree, pre);
    while (pRootOfTree->left) pRootOfTree = pRootOfTree->left;
    return pRootOfTree;
  }
private:
  void go(TreeNode* root, TreeNode* &pre) {
    if (!root) return;
    // LVR
    go(root->left, pre);
    if(pre)pre->right = root;
    root->left = pre;
    pre = root;
    go(root->right, pre);
  }
};

#else

class Solution {
public:
  TreeNode* Convert(TreeNode* pRootOfTree) {
    if (!pRootOfTree) return nullptr;
    // LVR
    stack<TreeNode*> st;
    push_left(pRootOfTree, st);
    TreeNode* pre = nullptr;
    TreeNode* res = st.top();
    while (!st.empty()) {
      TreeNode* r = st.top(); st.pop();
      push_left(r->right, st);
      r->left = pre;
      if (pre) pre->right = r;
      pre = r;
    }
    return res; 
  }
private:
  void push_left(TreeNode* root, stack<TreeNode*>& st) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }
};

#endif

#endif

void PrintLink(TreeNode* root) {
  while (root) {
    cout << root->val << ", ";
    root = root->right;
  }
  cout << endl;
}

int main() {
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  PrintLink(Solution().Convert(root));
  return 0;
}
