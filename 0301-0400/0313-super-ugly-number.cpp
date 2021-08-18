#include "common.h"

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> dp(n); dp[0] = 1;
    const int P = primes.size();
    vector<int> inds(P, 0);
    for (int i = 1; i < n; ++i) {
      int mv = dp[inds[0]] * primes[0];
      for (int j = 1; j < P; ++j) {
        int v = dp[inds[j]] * primes[j];
        mv = min(v, mv);
      }
      dp[i] = mv;
      for (int j = 0; j < P; ++j) {
        if (dp[inds[j]] * primes[j] == mv) ++inds[j];
      }
    }
    return dp.back();
  }
};

int main() {
  int n = 12; vector<int> primes{2, 7, 13, 19};
  cout << Solution().nthSuperUglyNumber(n, primes) << endl;
  return 0;
}
