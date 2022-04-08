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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
      if (!root) return true;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        {
          int qsize = q.size();
          // odd
          TreeNode *last = nullptr;
          while (qsize-- > 0) {
            TreeNode *r = q.front(); q.pop();
            if (!(r->val & 1)) return false;
            if (last) {
              if (last->val >= r->val) return false;
            }
            last = r;
            if (r->left) q.push(r->left);
            if (r->right) q.push(r->right);
          }
        }
        {
          int qsize = q.size();
          // odd
          TreeNode *last = nullptr;
          while (qsize-- > 0) {
            TreeNode *r = q.front(); q.pop();
            if ((r->val & 1)) return false;
            if (last) {
              if (last->val <= r->val) return false;
            }
            last = r;
            if (r->left) q.push(r->left);
            if (r->right) q.push(r->right);
          }
        }

      }
      return true;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
      if (!root) return true;
      queue<TreeNode*> q;
      q.push(root);

      auto check = [&](function<bool(int x)> is_odd, function<bool(int a, int b)> cmp) -> bool {
        int qsize = q.size();
        // odd
        TreeNode *last = nullptr;
        while (qsize-- > 0) {
          TreeNode *r = q.front(); q.pop();
          if (!(is_odd(r->val))) return false;
          if (last) {
            if (!(cmp(last->val, r->val))) return false;
          }
          last = r;
          if (r->left) q.push(r->left);
          if (r->right) q.push(r->right);
        }
        return true;
      };
      while (!q.empty()) {
        if (!(check([](int x) {return x & 1;}, [](int a, int b){return a < b;}))) return false;
        if (!(check([](int x) {return !(x & 1);}, [](int a, int b){return a > b;}))) return false;
      }
      return true;
    }
};

#endif
