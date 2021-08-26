#include "common.h"

class Solution {
public:
  int checkRecord(int n) {
    // ALP: 012
    // [A_cnt][L_cnt]
    int dp[2][2][3];
    memset(dp[0], 0, sizeof(dp[0]));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
      const int cur = i & 1;
      const int next = 1 - cur;
      memset(dp[next], 0, sizeof(dp[next]));
      // A_cnt
      for (int j = 0; j < 2; ++j) {
        // L_cnt
        for (int k = 0; k < 3; ++k) {
          // A
          if (j > 0) dp[next][j][0] = (dp[next][j][0] + dp[cur][j-1][k]) % MOD;
          // L
          if (k > 0) dp[next][j][k] = (dp[next][j][k] + dp[cur][j][k - 1]) % MOD;
          // P
          dp[next][j][0] = (dp[next][j][0] + dp[cur][j][k]) % MOD;
        }
      } 
    }
    int ans = 0;
    const int cur = n & 1;
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 3; ++k) {
        ans += dp[cur][j][k];
        ans %= MOD;
      }
    }
    return ans;
  }
private:
  static const int MOD = int(1e9) + 7;
};

int main() {
  int n = 10101;
  cout << Solution().checkRecord(n) << endl;
  return 0;
}
