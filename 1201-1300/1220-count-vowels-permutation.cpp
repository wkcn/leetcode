#include "common.h"

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = int(1e9) + 7;
        if (n == 0) return 0;
        // aeiou -> 01234
        int dp[2][5] = {{1, 1, 1, 1, 1}};
        for (int i = 1; i < n; ++i) {
            int e = i & 1;
            int c = 1 - e;
            dp[e][0] = ((dp[c][1] + dp[c][2]) % MOD + dp[c][4]) % MOD;
            dp[e][1] = (dp[c][0] + dp[c][2]) % MOD;
            dp[e][2] = (dp[c][1] + dp[c][3]) % MOD;
            dp[e][3] = (dp[c][2]) % MOD;
            dp[e][4] = (dp[c][2] + dp[c][3]) % MOD;
        }
        int e = 1 - (n & 1);
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans = (ans + dp[e][i]) % MOD;
        }
        return ans;
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().countVowelPermutation(n) << endl;
  return 0;
}
