#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    bool balanced = true;
    check(root, balanced);
    return balanced;
  }
private:
  int check(TreeNode* root, bool &balanced) {
    if (!balanced) return -1;
    if (!root) return 0;
    int dl = check(root->left, balanced);
    int dr = check(root->right, balanced);
    int diff = dl - dr;
    if (diff < -1 || diff > 1) balanced = false;
    return max(dl, dr) + 1;
  }
};

int main() {
  TreeNode *root = INPUT_BTREE_LEVEL<TreeNode>();
  cout << Solution().isBalanced(root) << endl;
  return 0;
}
