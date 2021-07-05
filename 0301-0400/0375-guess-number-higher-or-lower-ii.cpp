#include "common.h"

class Solution {
public:
  int getMoneyAmount(int n) {
    // dp[i][i] = i
    // dp[left][right] = i + max(dp[left][i - 1], dp[i + 1][right])
    vector<vector<int> > dp(n, vector<int>(n));
    for (int len = 2; len <= n; ++len) {
      for (int left = 0; left <= n - len; ++left) {
        int right = left + len - 1;
        int mi = INT32_MAX;
        for (int g = left; g <= right; ++g) {
          int a = g - 1 >= left ? dp[left][g - 1] : 0;
          int b = g + 1 <= right ? dp[g + 1][right] : 0;
          mi = min(mi, g + max(a, b));
        }
        dp[left][right] = mi;
      }
    }
    return dp[0][n - 1];
  }
};

int main() {
  cout << Solution().getMoneyAmount(10) << endl;
  return 0;
}
