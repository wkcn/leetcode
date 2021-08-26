#include "common.h"

class Solution {
public:
    int countArrangement(int n) {
      const int M = 1 << n;
      vector<int> dp(M, 0);
      dp[0] = 1;
      for (int e = 1; e <= n; ++e) {
        for (int j = M - 1; j >= 0; --j) {
          dp[j] = 0;
          for (int u = 1; u <= n; ++u) {
            int t = 1 << (u - 1);
            if ((j & t) && ((u % e == 0) || (e % u == 0))) {
              dp[j] += dp[j ^ t];
            }
          }
        }
      }
      return dp[M - 1];
    }
};

int main() {
  int n = 2;
  cout << Solution().countArrangement(n) << endl;
  return 0;
}
