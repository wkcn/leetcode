#include "common.h"

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int MOD = int(1e9) + 7;
class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<int>> dp2(m, vector<int>(n, 0));
    dp[startRow][startColumn] = 1;
    int ans = 0;
    while (maxMove-- > 0) {
      for (int c = 0; c < n; ++c) {
        ans = (ans + dp[0][c]) % MOD;
        ans = (ans + dp[m - 1][c]) % MOD;
      }
      for (int r = 0; r < m; ++r) {
        ans = (ans + dp[r][0]) % MOD;
        ans = (ans + dp[r][n - 1]) % MOD;
      }
      for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
          int cnt = 0;
          for (int d = 0; d < 4; ++d) {
            unsigned int nr = r + dirs[d][0];
            unsigned int nc = c + dirs[d][1];
            if (nr < m && nc < n) {
              cnt = (cnt + dp[nr][nc]) % MOD;
            }
          }
          dp2[r][c] = cnt;
        }
      }
      auto tmp = move(dp);
      dp = move(dp2);
      dp2 = move(tmp);
    }
    return ans;
  }
};

int main() {
  int m = 2, n = 2;
  int maxMove = 2;
  int startRow = 0, startColumn = 0;
  cout << Solution().findPaths(m, n, maxMove, startRow, startColumn) << endl;
  return 0;
}
