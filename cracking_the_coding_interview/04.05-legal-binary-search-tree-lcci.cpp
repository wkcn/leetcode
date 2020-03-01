/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode *root, TreeNode *low, TreeNode *high) {
        if (!root) return true;
        if (low && root->val <= low->val) return false;
        if (high && root->val >= high->val) return false;
        return isValidBST(root->left, low, root) && isValidBST(root->right, root, high);
    }
};
#elif SOLUTION == 2

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if (!root) return true;
      // LVR
      stack<TreeNode*> st;
      PushLeft(root, st);
      TreeNode *prev = nullptr;
      while (!st.empty()) {
        TreeNode *r = st.top(); st.pop();
        if (prev && prev->val >= r->val) return false;
        prev = r;
        PushLeft(r->right, st);
      }
      return true;
    }
    void PushLeft(TreeNode *r, stack<TreeNode*> & st) {
      while (r) {
        st.push(r); r = r->left;
      }
    }
};
#endif
