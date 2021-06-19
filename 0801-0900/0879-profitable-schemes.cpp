#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
const int MOD = 1000000007;
int dp[101][101];
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      // 状态: 完成第i个工作后, 至少产生p利润, 并且员工人数剩余m
      // dp[i][p][m] = dp[i - 1][p][m] + dp[i - 1][p - profit[i]][m + group[i]]
      // 有多少种计划可选
      memset(dp, 0, sizeof(dp));
      for (int m = 0; m <= n; ++m) {
        dp[0][m] = 1;
      }
      for (int i = 0; i < group.size(); ++i) {
        // 注意这里对p的处理
        // profit[i]有可能大于等于p
        for (int p = minProfit; p >= 0; --p) {
          for (int m = 0; m <= n - group[i]; ++m) {
            dp[p][m] += dp[max(p - profit[i], 0)][m + group[i]];
            dp[p][m] %= MOD;
          }
        }
      }
      return dp[minProfit][0];
    }
};
#elif SOLUTION == 2

const int MOD = 1e9 + 7;
int dp[101][101];
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      // dp[p][m], 最少p利润, 用了最多m个人
      memset(dp, 0, sizeof(dp));
      for (int m = 0; m <= n; ++m) {
        dp[0][m] = 1;
      }
      for (int i = 0; i < group.size(); ++i) {
        for (int p = minProfit; p >= 0; --p) {
          for (int m = n; m >= group[i]; --m) {
            dp[p][m] += dp[max(0, p - profit[i])][m - group[i]];
            dp[p][m] %= MOD;
          }
        }
      }
      return dp[minProfit][n];
    }
};

#endif

int main() {
  {
    int n = 5;
    int minProfit = 3;
    vector<int> group{2, 2};
    vector<int> profit{2, 3};
    cout << Solution().profitableSchemes(n, minProfit, group, profit) << endl;
  }

  {
    int n = 10;
    int minProfit = 5;
    vector<int> group{2, 3, 5};
    vector<int> profit{6, 7, 8};
    cout << Solution().profitableSchemes(n, minProfit, group, profit) << endl;
  }
  return 0;
}
