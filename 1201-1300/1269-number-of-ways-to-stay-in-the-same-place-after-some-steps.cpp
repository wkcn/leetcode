#include "common.h"

// 优化边界, 比如走一半, 超过一半是不会走回去的
// 算清楚
const int MOD = 1000000007;
int dp[2][252];
class Solution {
public:
    int numWays(int steps, int arrLen) {
      // 因为最多500步, 最多可以走到index 500的地方
      memset(&dp, 0, sizeof(dp));
      dp[0][0] = 1;
      int cur = 0;
      const int n = min(steps / 2 + 1, arrLen); 
      if (n == 1) return 1;
      for (int s = 0; s < steps; ++s) {
        int next = 1 - cur;
        dp[next][0] = (dp[cur][0] + dp[cur][1]) % MOD;
        for (int i = 1; i < n; ++i) {
          dp[next][i] = ((dp[cur][i] + dp[cur][i - 1]) % MOD + dp[cur][i + 1]) % MOD;
        }
        cur = 1 - cur;
      }
      return dp[cur][0];
    }
};

int main() {
  cout << Solution().numWays(3, 2) << endl;
  cout << Solution().numWays(2, 4) << endl;
  cout << Solution().numWays(4, 2) << endl;
  return 0;
}
