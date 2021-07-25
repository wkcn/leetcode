#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      if (s.empty()) return 0;
      const int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = 0; i < n; ++i) dp[i][i] = 1;
      for (int i = 0; i < n - 1; ++i) dp[i][i+1] = s[i] == s[i + 1] ? 2 : 1;
      for (int L = 3; L <= n; ++L) {
        for (int left = 0; left <= n - L; ++left) {
          // [left, left + L)
          if (s[left] == s[left + L - 1]) {
            dp[left][left + L - 1] = dp[left + 1][left + L - 2] + 2; 
          } else {
            dp[left][left + L - 1] = max(dp[left][left + L - 2], dp[left + 1][left + L - 1]); 
          }
        }
      }
      return dp[0][n - 1];
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      if (s.empty()) return 0;
      const int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n - 1; ++j) {
          // [i, j]
          if (s[i] == s[j]) {
            dp[i][j] = j - i >= 2 ? dp[i + 1][j - 1] + 2 : 2;
          } else {
            dp[i][j] = max(dp[i+1][j], dp[i][j - 1]);
          }
        }
      }
      return dp[0][n - 1];
    }
};

#endif

int main() {
  {
  string s = "bbbab";
  cout << Solution().longestPalindromeSubseq(s) << endl;
  }
  {
  string s = "cbbd";
  cout << Solution().longestPalindromeSubseq(s) << endl;
  }
  return 0;
}
