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
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) { 
    if (pRoot1 == NULL || pRoot2 == NULL) return false;
    return IsSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
  }
private:
  bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == NULL) return true;
    if (pRoot1 == NULL) return false;
    if (pRoot1->val != pRoot2->val) return false;
    return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right); 
  }
};

int main() {
  TreeNode* r1 = INPUT_BTREE_VLR<TreeNode>();
  TreeNode* r2 = INPUT_BTREE_VLR<TreeNode>();
  cout << Solution().HasSubtree(r1, r2) << endl;
  return 0;
}
