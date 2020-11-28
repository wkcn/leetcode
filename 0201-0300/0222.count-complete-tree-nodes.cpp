class Solution {
public:
    int countNodes(TreeNode* root) {
      /*
                0001
            0010    0011
    0100     0101  0110     0111
1000|1001|1010|1011|1100|1101|1110|1111
       H = (最大节点ID - 1) / 2 + 1
       t = 4
       选这个, 首先定位到最高位的1, 然后开始移动

                0000
            0001    0010
    0011     0100  0101     0110
0111|1000|1001|1010|1011|1100|1101|1110
        left = parent * 2 + 1
        right = parent * 2 + 2
       */
      if (!root) return 0;
      int t = 0;
      TreeNode *r = root;
      while (r) {
          r = r->left;
          ++t;
      }
      if (t == 1) return 1;
      // t是可能的最大高度
      int lo = 1 << (t-1), hi = 1 << t;
      while (lo < hi) {
          int mid = lo + ((hi - lo) >> 1);
          if (existed(root, t, mid)) {
              lo = mid + 1;
          } else {
              hi = mid;
          }
      }
      return --lo;
    }
    bool existed(TreeNode *r, int t, int v) {
        // 
        int b = 1 << (t - 2);
        while (r && b > 0) {
            if (v & b) {
                r = r->right;
            } else {
                r = r->left;
            }
            b >>= 1;
        }
        return r;
    }
};
