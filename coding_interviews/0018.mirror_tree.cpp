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
    void Mirror(TreeNode *pRoot) {
      if (pRoot == NULL) return;
      TreeNode* tmp = pRoot->left;
      pRoot->left = pRoot->right;
      pRoot->right = tmp;
      Mirror(pRoot->left);
      Mirror(pRoot->right);
    }
};

int main() {
  TreeNode* r1 = INPUT_BTREE_VLR<TreeNode>();
  Solution().Mirror(r1);
  PRINT_BTREE_VLR(r1);
  return 0;
}
