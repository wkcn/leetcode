#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
int dp[10001];
class Solution {
public:
    int numSquares(int n) {
      fill(dp, dp + (n + 1), INT32_MAX);
      dp[0] = 0;
      const int s = sqrt(n);
      for (int i = 1; i <= s; ++i) {
        const int w = i * i;
        for (int e = 0; e <= n - w; ++e) {
          dp[e + w] = min(dp[e + w], dp[e] == INT32_MAX ? INT32_MAX : dp[e] + 1);
        }
      }
      return dp[n];
    }
};
#elif SOLUTION == 2
int dp[10001];
class Solution {
public:
    int numSquares(int n) {
      dp[0] = 0;
      for (int i = 1; i <= n; ++i) {
        // assign dp[i]
        int minv = INT32_MAX;
        for (int e = 1; e * e <= i; ++e) {
          const int w = e * e;
          minv = min(minv, dp[i - w]);
        }
        dp[i] = minv + 1;
      }
      return dp[n];
    }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().numSquares(n) << endl;
  return 0;
}
