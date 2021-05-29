#include "common.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      const int rows = matrix.size();
      const int cols = matrix[0].size();
      vector<int> rsum(cols);
      int ans = 0;
      for (int r_start = 0; r_start < rows; ++r_start) {
        fill(rsum.begin(), rsum.end(), 0);
        for (int r_end = r_start; r_end < rows; ++r_end) {
          // [r_start, r_end]
          for (int c = 0; c < cols; ++c) {
            rsum[c] += matrix[r_end][c];
          }
          // compute pre-sum
          unordered_map<int, int> cnts;
          cnts[0] = 1;
          int pre = 0;
          for (int c = 0; c < cols; ++c) {
            pre += rsum[c];
            auto p = cnts.find(pre - target);
            if (p != cnts.end()) {
              ans += p->second;
            }
            ++cnts[pre];
          }
        }
      }
      return ans;
    }
};

int main() {
  vector<vector<int>> matrix = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
  int target = 0;
  cout << Solution().numSubmatrixSumTarget(matrix, target) << endl;
  return 0;
}
