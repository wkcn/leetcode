#include "common.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      const int rows = matrix.size();
      const int cols = matrix[0].size();
      vector<int> dp(cols, 0);
      int ans = 0;
      for (int r = 0; r < rows; ++r) {
        int oldv = dp[0];
        dp[0] = matrix[r][0] == '1';
        // notice here
        ans = max(ans, dp[0]);
        for (int c = 1; c < cols; ++c) {
          if (matrix[r][c] == '1') {
            int mi = min({oldv, dp[c-1], dp[c]});
            oldv = dp[c];
            dp[c] = mi + 1;
            ans = max(dp[c], ans);
          } else {
            oldv = dp[c];
            dp[c] = 0;
          }
        }
      }
      return ans * ans;
    }
};

int main() {
  vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  cout << Solution().maximalSquare(matrix) << endl;
  return 0;
}
