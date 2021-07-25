#include "common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      const int rows = grid.size();
      const int cols = grid[0].size();
      vector<int> dp(cols);
      dp[0] = grid[0][0];
      for (int c = 1; c < cols; ++c) {
        dp[c] = dp[c - 1] + grid[0][c];
      }
      for (int r = 1; r < rows; ++r)  {
        dp[0] += grid[r][0];
        for (int c = 1; c < cols; ++c) {
          dp[c] = min(dp[c], dp[c - 1]) + grid[r][c]; 
        }
      }
      return dp.back();
    }
};

int main() {
  vector<vector<int>> grid{{1,3,1}, {1,5,1}, {4,2,1}};
  cout << Solution().minPathSum(grid) << endl;
  return 0;
}
