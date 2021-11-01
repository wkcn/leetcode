#include "common.h"

class Solution {
public:
    int numDecodings(string s) {
      if (s.empty() || s[0] == '0') return 0;
      using LL = long long;
      const LL MOD = LL(1e9) + 7;
      const int n = s.size();
      vector<LL> dp(n + 1);
      dp[0] = 1;
      dp[1] = (s[0] != '*') ? 1 : 9;
      for (int i = 1; i < n; ++i) {
        if (s[i] == '*') {
          dp[i + 1] = (dp[i] * 9) % MOD;
          if (s[i - 1] == '1') dp[i + 1] = (dp[i + 1] + dp[i - 1] * 9) % MOD;
          else if (s[i - 1] == '2') dp[i + 1] = (dp[i + 1] + dp[i - 1] * 6) % MOD;
          else if (s[i - 1] == '*') dp[i + 1] = (dp[i + 1] + dp[i - 1] * 15) % MOD;  // **
        } else {
          dp[i + 1] = s[i] == '0' ? 0 : dp[i];  // kind
          switch (s[i - 1]) {
            case '*':
              dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
              if (s[i] <= '6')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
              break;
            case '1':
              dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
              break;
            case '2':
              if (s[i] <= '6')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
              break;
          }
        }
        // PRINT_ARRAY(dp);
      }
      return dp.back();
    }
};

int main() {
  while (1) {
    string s; cin >> s;
    cout << Solution().numDecodings(s) << endl;
  }
  return 0;
}
