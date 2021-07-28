#include "common.h"

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      if (mat.empty()) return {};
      if (mat[0].empty()) return {};
      const int rows = mat.size();
      const int cols = mat[0].size();
      vector<vector<int>> presum(rows+1, vector<int>(cols+1));
      fill(presum[0].begin(), presum[0].end(), 0);
      for (int r = 1; r <= rows; ++r) {
        presum[r][0] = 0;
      }
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          presum[r+1][c+1] = presum[r+1][c] + presum[r][c+1] - presum[r][c] + mat[r][c];
        }
      }
      vector<vector<int>> ans(rows, vector<int>(cols));
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          const int minr = max(r-k, 0);
          const int minc = max(c-k, 0);
          const int maxr = min(r+k+1, rows);
          const int maxc = min(c+k+1, cols);
          ans[r][c] = presum[maxr][maxc] - presum[minr][maxc] - presum[maxr][minc] + presum[minr][minc];
        }
      }
      return ans;
    }
};

int main() {
  vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
  int k = 1;
  PRINT_ARRAY2D(Solution().matrixBlockSum(mat, k));
  return 0;
}
