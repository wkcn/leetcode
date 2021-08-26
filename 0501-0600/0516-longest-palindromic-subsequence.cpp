#include "common.h"

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) dp[i][i+1] = s[i] == s[i + 1] ? 2 : 1;
    for (int len = 3; len <= n; ++len) {
      for (int i = 0, j = len - 1; j < n; ++i, ++j) {
        dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] + 2 : max(dp[i][j-1], dp[i+1][j]);
      }
    }
    return dp[0][n-1];
  }
};

int main() {
  string s = "bbbab";
  cout << Solution().longestPalindromeSubseq(s) << endl;
  return 0;
}
