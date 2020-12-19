#include "common.h"

// 简化成一个简单的问题
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        if (n == 0) return {};
        vector<int> ans;
        // 先假设全部都按左下方向走, 出发点在top和right边
        for (int k = 0; k < n + m - 1; ++k) {
          const int r = max(0, k - n + 1); 
          const int c = min(k, n - 1);
          // 计算目标, 偏移(1, -1)
          int step = min(m - r - 1, c); 
          if (k & 1) {
            // left bottom
            int sr = r;
            int sc = c;
            while (step-- >= 0) {
              ans.push_back(matrix[sr][sc]);
              ++sr; --sc;
            }
          } else {
            // right top
            int sr = r + step;
            int sc = c - step;
            while (step-- >= 0) {
              ans.push_back(matrix[sr][sc]);
              --sr; ++sc;
            }
          }
        }
        return ans;
    }
};

int main() {
  vector<vector<int> > nums;
  INPUT_ARRAY2D(nums);
  PRINT_ARRAY(Solution().findDiagonalOrder(nums));
  return 0;
}
