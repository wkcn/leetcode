#include "common.h"

int dp[501][501];
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
      // dp[i][j] 表示在[i, j]范围内, 先手优先的最高分数
      for (int i = 0; i < piles.size(); ++i) {
        dp[i][i] = piles[i];
      }
      for (int len = 2; len <= piles.size(); ++len) {
        for (int i = 0; i <= (int)piles.size() - len; ++i) {
          // 取i或者取i + len - 1
          dp[i][i + len - 1] = max(piles[i] - dp[i+1][i + len - 1],
                                   piles[i + len - 1] - dp[i][i + len - 2]);
        } 
      }

      return dp[0][piles.size() - 1] > 0;
    }
};

int main() {
  vector<int> piles{5, 3, 4, 5};
  cout << Solution().stoneGame(piles) << endl;
  return 0;
}
