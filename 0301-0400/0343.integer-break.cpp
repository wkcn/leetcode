// TODO: 其他数学解法
#include "common.h"

class Solution {
public:
    int integerBreak(int n) {
        // dp[k]存的是至少两个数构成的，没有一个数构成的
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int ma = 0;
            for (int j = 1; j < i; ++j) {
                ma = max({ma, j * dp[i - j], j * (i - j)});
            }
            dp[i] = ma;
        }
        return dp[n];
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().integerBreak(n) << endl;
  return 0;
}
