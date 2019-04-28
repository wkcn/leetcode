#include "common.h"
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
// recursive
/*
 Runtime: 20 ms, faster than 99.00% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 20.6 MB, less than 51.64% of C++ online submissions for Validate Binary Search Tree.
 */
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, nullptr, nullptr);
  }
private:
  bool isValidBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
  }
};
#else

#if 0
// Queue
/*
 Runtime: 20 ms, faster than 99.00% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 5.15% of C++ online submissions for Validate Binary Search Tree.
 */
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    queue<Node3> q;
    q.push({root, nullptr, nullptr});
    while (!q.empty()) {
      Node3 n3 = q.front(); q.pop();
      TreeNode* root = get<0>(n3);
      if (!root) continue;
      TreeNode* minNode = get<1>(n3);
      TreeNode* maxNode = get<2>(n3);
      if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
      q.push({root->left, minNode, root});
      q.push({root->right, root, maxNode});
    }
    return true;
  }
private:
  using Node3 = tuple<TreeNode*, TreeNode*, TreeNode*>;
};
#else

/*
 Runtime: 20 ms, faster than 99.00% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 20.7 MB, less than 28.39% of C++ online submissions for Validate Binary Search Tree.
 */
// inorder
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    stack<TreeNode*> st;
    push_left(st, root);
    TreeNode* pre = nullptr;
    while (!st.empty()) {
      TreeNode* e = st.top(); st.pop();
      if (pre && pre->val >= e->val) return false;
      pre = e;
      if (e->right) push_left(st, e->right);
    }
    return true;
  }
private:
  void push_left(stack<TreeNode*> &st, TreeNode* root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }
};

#endif // queue

#endif // recursive

int main() {
  TreeNode* root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().isValidBST(root) << endl;
  return 0;
}
