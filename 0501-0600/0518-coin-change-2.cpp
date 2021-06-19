// 注意DP顺序
#include "common.h"

#define SOLUTION 1

#if SOLUTION == 1
class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<int> dp(amount + 1);
      dp[0] = 1;
      for (int x : coins) {
        for (int i = x; i <= amount; ++i) {
          dp[i] += dp[i - x];
        }
      }
      return dp[amount];
    }
};
#elif SOLUTION == 2

#endif

int main() {
  {
    int amount = 5;
    vector<int> coins{1, 2, 5};
    cout << Solution().change(amount, coins) << endl;
  }
  return 0;
}
