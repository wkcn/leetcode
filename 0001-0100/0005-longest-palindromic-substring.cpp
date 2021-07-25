#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    string longestPalindrome(string s) {
      if (s.empty()) return {};
      const int n = s.size();
      const int m = 2 * n + 3;
      string t(m, '#');
      t[0] = '^'; t.back() = '$';
      for (int i = 0, j = 2; i < s.size(); ++i, j += 2) {
        t[j] = s[i];
      }
      int best_i = -1;
      int best_len = 0;
      for (int i = 2; i < m - 2; ++i) {
        const int r = min(i, m - i);
        for (int k = 1; k <= r; ++k) {
          if (t[i - k] != t[i + k]) break;
          if (k > best_len) {
            best_len = k;
            best_i = i;
          }
        }
      }
      // ^#b#a#b#a#d#$
      int left = (best_i - best_len) / 2;
      return s.substr(left, best_len);
    }
};
#elif SOLUTION == 2

class Solution {
public:
    string longestPalindrome(string s) {
      if (s.empty()) return {};
      const int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = 0; i < n; ++i) dp[i][i] = 1;
      for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) dp[i][i + 1] = 2;
      }
      for (int k = 2; k < n; ++k) {
        // [left, left + k]
        for(int left = 0; left < n - k; ++left) {
          if(s[left] == s[left + k] && dp[left+1][left+k-1] > 0) {
            dp[left][left + k] = dp[left+1][left + k -1] + 2;
          }
        }
      }
      int best_left = 0;
      int best_len = 0;
      for (int t = n; t >= 1; --t) {
        for (int left = 0; left < n - t + 1; ++left) {
          int len = dp[left][left + t - 1];
          if (len > best_len) {
            best_len = len;
            best_left = left;
          }
        }
      }
      return s.substr(best_left, best_len);
    }
};

#elif SOLUTION == 3

class Solution {
public:
    string longestPalindrome(string s) {
      if (s.empty()) return {};
      const int n = s.size();
      const int m = 2 * n + 3;
      string t(m, '#');
      t[0] = '^'; t.back() = '$';
      for (int i = 0, j = 2; i < s.size(); ++i, j += 2) {
        t[j] = s[i];
      }
      vector<int> M(m);
      int C = 0;
      for (int i = 2; i < m - 2; ++i) {
        int i_mirror = 2 * C - i;
        if (i_mirror >= 0 && M[i_mirror]
      } 
    }
};
#endif

int main() {
  if (0) {
  string s = "babad";
  cout << Solution().longestPalindrome(s) << endl;
  }
  {
  string s = "aacabdkacaa";
  cout << Solution().longestPalindrome(s) << endl;
  }
  return 0;
}
