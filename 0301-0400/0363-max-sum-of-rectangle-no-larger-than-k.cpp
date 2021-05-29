#include "common.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      const int rows = matrix.size();
      if (rows == 0) return 0;
      const int cols = matrix[0].size();
      if (cols == 0) return 0;
      if (rows * log(cols) > cols * log(rows)) {
        vector<vector<int>> tmatrix(cols, vector<int>(rows));
        for (int r = 0; r < rows; ++r) {
          for (int c = 0; c < cols; ++c) {
            tmatrix[c][r] = matrix[r][c];
          }
        }
        return maxSumSubmatrix(tmatrix, k);
      }
      int ans = INT32_MIN;
      // time: O(rows ^ 2 * cols * log(cols))
      vector<int> rsum(cols, 0);
      for (int up = 0; up < rows; ++up) {
        // [up, down]
        // down 是从上到下的
        fill(rsum.begin(), rsum.end(), 0);
        for (int down = up; down < rows; ++down) {
          for (int c = 0; c < cols; ++c) {
            rsum[c] += matrix[down][c];
          }
          // compute presum
          int presum = 0;
          set<int> se{0};
          // a - b <= k, b in se
          // b >= a - k, b in se, max (a - b), min b
          for (int c = 0; c < cols; ++c) {
            // 要在se中找刚刚好大于等于a - k的数
            presum += rsum[c];
            auto p = se.lower_bound(presum - k);
            if (p != se.end()) ans = max(ans, presum - *p);
            se.insert(presum);
          }
        }
      }
      return ans;
    }
};

int main() {
  vector<vector<int>> matrix{{1, 0, 1}, {0, -2, 3}};
  int k = 2;
  cout << Solution().maxSumSubmatrix(matrix, k) << endl;
  return 0;
}
