#include "common.h"

int dp[101][101];
class Solution {
public:
    int strangePrinter(string s) {
      // [i, j]
      // dp[i][j] 表示[i, j]内的字符串的最少打印次数
      // dp[i][j] 和 {dp[i-1][j], dp[i][j+1]}
      // case 1: s[i] == s[j]
      //   可以在第一步打印s[i]和s[j]
      //   dp[i][j] = dp[i][j - 1]
      // case 2: s[i] != s[j]
      //   dp[i][k] + dp[k + 1][j]
      //   长的可以分两段算.
      //   ddd
#define SOLUTION 2
#if SOLUTION == 2
      s.resize(unique(s.begin(), s.end()) - s.begin());
#endif
      const int n = s.size();
      for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
      }
      for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i][j - 1];
          } else {
            int v = 1 + dp[i+1][j];  // k == i
            // 注意边界条件
            for (int k = i + 1; k < j; ++k) {
              v = min(v, dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = v;
          }
        }
      }
      return dp[0][n - 1];
    }
};

int main() {
  cout << Solution().strangePrinter("aaabbb") << endl;
  cout << Solution().strangePrinter("aba") << endl;
  cout << Solution().strangePrinter("aabbbaaabbb") << endl;
  return 0;
}
