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
  bool IsBalanced_Solution(TreeNode* pRoot) {
    return is_balanced_tree(pRoot) >= 0;
  }
private:
  int is_balanced_tree(TreeNode* r) {
    if (!r) return 0;
    int left = is_balanced_tree(r->left);
    int right = is_balanced_tree(r->right);
    if (left < 0 || right < 0) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }
};

int main() {
  TreeNode* root = INPUT_BTREE_VLR<TreeNode>();
  cout << Solution().IsBalanced_Solution(root) << endl;
  return 0;
}
