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
  vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* r = q.front(); q.pop();
      if (!r) continue;
      res.push_back(r->val);
      q.push(r->left);
      q.push(r->right);
    }
    return res;
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  PRINT_BTREE_LEVEL(root);
  PRINT_ARRAY(Solution().PrintFromTopToBottom(root));
  return 0;
}
