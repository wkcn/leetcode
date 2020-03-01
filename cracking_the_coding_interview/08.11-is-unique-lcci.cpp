#include "common.h"
/*
 * 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
 */

// C++ 自由存储区是否等价于堆？
// 在C++中，内存区分为5个区，分别是堆、栈、自由存储区、全局/静态存储区、常量存储区
// https://www.cnblogs.com/QG-whz/p/5060894.html
// 
// 
// 多重背包
// TODO: 还可以转为一个一维数组, 可以通过更改循环初值消除一些if语句
#define SOLUTION 4

#if SOLUTION == 1

int dp[4][1000001]; // 大数组

class Solution {
public:
    int waysToChange(int n) {
      if (n == 0) return 0;
      const int MOD = 1000000007;
      int coins[4] = {1, 5, 10, 25};
      // 50是25, 10, 5, 1的最小公倍数
      // dp[i][j] = dp[i-1][j] + d[i][j-coins[i]]
      for (int i = 0; i < 4; ++i) dp[i][0] = 1;
      for (int j = 1; j <= n; ++j) {
        dp[0][j] = dp[0][j - coins[0]]; // j >= coins[0]
        for (int i = 1; i < 4; ++i) {
          if (j >= coins[i]) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i]]) % MOD;
          } else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
      return dp[3][n];
    }
};

#elif SOLUTION == 2

int dp[4][1000001]; // 大数组

class Solution {
public:
    int waysToChange(int n) {
      if (n == 0) return 0;
      const int MOD = 1000000007;
      int coins[4] = {1, 5, 10, 25};
      // 50是25, 10, 5, 1的最小公倍数
      // dp[i][j] = dp[i-1][j] + d[i][j-coins[i]]
      for (int i = 0; i < 4; ++i) dp[i][0] = 1;
      for (int i = 0; i < 4; ++i) {
        if (i == 0) {
          for (int j = coins[0]; j <= n; ++j) {
            dp[0][j] = dp[0][j - coins[0]];
          }
        } else {
          for (int j = 1; j <= n; ++j) {
            if (j >= coins[i]) {
              dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i]]) % MOD;
            } else {
              dp[i][j] = dp[i - 1][j];
            }
          }
        }
      }
      return dp[3][n];
    }
};

#elif SOLUTION == 3

// 压缩i, i只需要存储当前状态和上一个状态
int dp[2][1000001]; // 大数组

class Solution {
public:
    int waysToChange(int n) {
      if (n == 0) return 0;
      const int MOD = 1000000007;
      int coins[4] = {1, 5, 10, 25};
      // 50是25, 10, 5, 1的最小公倍数
      // dp[i][j] = dp[i-1][j] + d[i][j-coins[i]]
      dp[0][0] = 1;
      dp[1][0] = 1;
      for (int i = 0; i < 4; ++i) {
        if (i == 0) {
          for (int j = coins[0]; j <= n; ++j) {
            dp[0][j] = dp[0][j - coins[0]];
          }
        } else {
          int cur = i & 1;
          int last = cur ^ 1;
          for (int j = 1; j <= n; ++j) {
            if (j >= coins[i]) {
              dp[cur][j] = (dp[last][j] + dp[cur][j - coins[i]]) % MOD;
            } else {
              dp[cur][j] = dp[last][j];
            }
          }
        }
      }
      return dp[1][n];
    }
};

#elif SOLUTION == 4

// 压缩j, j需要当前状态和近25个状态

int dp[4][26]; // 大数组

class Solution {
public:
    int waysToChange(int n) {
      if (n == 0) return 0;
      const int MOD = 1000000007;
      int coins[4] = {1, 5, 10, 25};
      // 50是25, 10, 5, 1的最小公倍数
      // dp[i][j] = dp[i-1][j] + d[i][j-coins[i]]
      for (int i = 0; i < 4; ++i) dp[i][0] = 1;
      for (int j = 1; j <= n; ++j) {
        int cur = j % 26;
        dp[0][cur] = dp[0][(j - coins[0]) % 26]; // j >= coins[0]
        for (int i = 1; i < 4; ++i) {
          if (j >= coins[i]) {
            dp[i][cur] = (dp[i - 1][cur] + dp[i][(j - coins[i]) % 26]) % MOD;
          } else {
            dp[i][cur] = dp[i - 1][cur];
          }
        }
      }
      return dp[3][n % 26];
    }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().waysToChange(n) << endl;
  return 0;
}
