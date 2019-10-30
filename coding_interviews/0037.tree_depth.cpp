#include "common.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

#if 0
class Solution {
public:
  int TreeDepth(TreeNode* pRoot) {
    if (!pRoot) return 0;
    int res = 0;
    queue<pair<TreeNode*,int> > q;
    q.push({pRoot, 1});
    while (!q.empty()) {
      pair<TreeNode*, int> p = q.front(); q.pop();
      TreeNode* t = p.first;
      int d = p.second;
      res = max(res, d);
      if (t->left) q.push({t->left, d+1});
      if (t->right) q.push({t->right, d+1});
    }
    return res;
  }
};
#else

class Solution {
public:
  int TreeDepth(TreeNode* pRoot) {
    if (!pRoot) return 0;
    return max(TreeDepth(pRoot->left)+1, TreeDepth(pRoot->right)+1);
  }
};

#endif

int main() {
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  cout << Solution().TreeDepth(root) << endl;
  return 0;
}
