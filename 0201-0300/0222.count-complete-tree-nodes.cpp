// TODO: 对最后一层编号
#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionNaive {
public:
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      map<int, TreeNode*> ma;
      int h = 0;
      TreeNode *r = root;
      int i = 0;
      while (r) {
        ma[i] = r;
        ++h;
        i = (i << 1) | 1;
        r = r->left;
      }
      int lo = (1 << (h-1)) - 1;
      int hi = (1 << h) - 1;
      stack<bool> st; // left false, right true
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1); 
        int u = mid;
        while (!ma.count(u)) {
          if (u & 1) {
            st.push(false);
            u >>= 1;
          } else {
            st.push(true);
            u = (u - 2) >> 1; 
          }
        }
        TreeNode *r = ma[u];
        while (!st.empty() && r) {
          ma[u] = r;
          bool right = st.top(); st.pop();
          if (right) {
            u = (u + 1) << 1;
            r = r->right;
          } else {
            u = (u << 1) | 1;
            r = r->left;
          }
        }
        if (r) {
          lo = mid + 1;
        } else {
          while (!st.empty()) st.pop();
          hi = mid;
        }
      }
      return lo;
    }
};

int main() {
  int n;
  cin >> n;
  vector<TreeNode*> vs;
  for (int i = 0; i < n; ++i) {
    vs.push_back(new TreeNode(i)); 
  }
  for (int i = 0; i < n; ++i) {
    if (i * 2 + 1 < n) vs[i]->left = vs[i * 2 + 1];
    if (i * 2 + 2 < n) vs[i]->right = vs[i * 2 + 2];
  }
  TreeNode *root = vs[0];
  cout << Solution().countNodes(root) << endl; 
  return 0;
}
