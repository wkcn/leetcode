// 区间DP [HARD]
#include "common.h"

// reference: https://leetcode-cn.com/problems/boolean-evaluation-lcci/solution/qu-jian-dp-by-lightcml/
int dp[40][40][2]; // dp[i][j][a=0或1] 从i到j(闭区间)个数字结果为a的方案数
class Solution {
public:
    int countEval(string s, int result) {
      function<int(bool, bool)> f[256];
      f['|'] = [](bool i, bool j) {return i | j;};
      f['&'] = [](bool i, bool j) {return i & j;};
      f['^'] = [](bool i, bool j) {return i ^ j;};
      const int n = (s.size() + 1) >> 1;
      memset(dp, 0, sizeof(dp));
      for (int len = 1; len <= n; ++len) { // 区间长度
        for (int i = 0; i + len <= n; ++i) { // 起始点[0, i+len-1]
          int j = i + len - 1; // 闭区间
          if (len == 1) dp[i][j][s[i<<1]-'0']=1;
          else {
            // 枚举区间分割点
            for (int k = i; k < j; ++k) {
              for (int a: {0, 1}) for (int b: {0, 1})
                if (dp[i][k][a] && dp[k+1][j][b])
                  dp[i][j][f[s[(k<<1)+1]](a, b)] += dp[i][k][a] * dp[k+1][j][b];
            }
          }
        }
      }
      return dp[0][n-1][result];
    }
};

int main() {
  string s; int result;
  cin >> s >> result;
  cout << Solution().countEval(s, result) << endl;
}
