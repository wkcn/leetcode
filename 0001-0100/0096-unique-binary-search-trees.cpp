#include "common.h"

class Solution {
public:
    int numTrees(int n) {
      if (n == 0) return 0;
      vector<int> dp(n + 1);
      dp[0] = 1;
      dp[1] = 1;
      for (int i = 2; i <= n; ++i) {
        for (int left = 0; left <= i - 1; ++left) {
          int right = i - 1 - left;
          dp[i] += dp[left] * dp[right];
        }
      } 
      return dp[n];
    }
};

int main() {
  cout << Solution().numTrees(4) << endl;
  cout << Solution().numTrees(3) << endl;
  cout << Solution().numTrees(1) << endl;
  return 0;
}
