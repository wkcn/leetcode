#include "common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* reConstructBinaryTree(vector<int> VLR,vector<int> LVR) {
    TreeNode* root = nullptr;
    int size = VLR.size();
    construct(VLR, LVR, &root, 0, size, 0, size); 
    return root;
  }
private:
  void construct(const vector<int> &VLR, const vector<int> &LVR, TreeNode** root, int l1, int r1, int l2, int r2) {
    if (r1 - l1 <= 0) return;
    int v = VLR[l1];
    int p;
    for (p = l2; p < r2; ++p) {
      if (LVR[p] == v) {
        break;
      }
    }
    *root = new TreeNode(v);
    int l_len = p - l2;
    construct(VLR, LVR, &((*root)->left), l1+1, l1+1+l_len, l2, p); 
    construct(VLR, LVR, &((*root)->right), l1+1+l_len, r1, p+1, r2); 
  }
};

void PrintLRV(TreeNode* root) {
  if (root->left) PrintLRV(root->left);
  if (root->right) PrintLRV(root->right);
  cout << root->val << ", ";
}

int main() {
  vector<int> VLR, LVR;
  INPUT_ARRAY(VLR);
  INPUT_ARRAY(LVR);
  // print LRV
  PrintLRV(Solution().reConstructBinaryTree(VLR, LVR));
  cout << endl;
  return 0;
}
