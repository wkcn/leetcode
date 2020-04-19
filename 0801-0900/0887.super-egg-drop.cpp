// 好题目
// TODO: 决策单调性, 官方题解后两种解法
#include "common.h"

int dp[101][10001];
class Solution {
public:
    int superEggDrop(int K, int N) {
      for (int n = 0; n <= N; ++n) dp[1][n] = n;
      for (int k = 0; k <= K; ++k) dp[k][0] = 0;
      for (int k = 2; k <= K; ++k) {
        /*
        for (int n = 1; n <= N; ++n) {
          dp[k][n] = INT32_MAX;
        }
        for (int n = 1; n <= N; ++n) {
          for (int m = 1; m <= n; ++m)
            dp[k][n] = min(dp[k][n], max(dp[k-1][m-1], dp[k][n-m]) + 1);
        }
        */
        for (int n = 1; n <= N; ++n) {
          // m: [1, n] 
          int lo = 1, hi = n + 1;
          while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int &a = dp[k-1][mid-1]; // 递增
            int &b = dp[k][n-mid]; // 递减
            a < b ? lo = mid + 1 : hi = mid; 
          }
          // lo and lo - 1
          // a和b两条直线画出来后，可能在最后的位置相等，因此lo不会等于n+1
          // 1 <= lo <= n
          int t = max(dp[k-1][lo-1], dp[k][n-lo]);
          if (lo >= 2)
            t = min(t, max(dp[k-1][(lo-1)-1], dp[k][n-(lo-1)])); 
          dp[k][n] = t + 1;
        }
      }
      /*
      for (int k = 1; k <= K; ++k) {
        for (int n = 1; n <= N; ++n) {
          cout << dp[k][n] << ", ";
        }
        cout << endl;
      }
      */
      return dp[K][N];
    }
};

int main() {
  int K, N;
  cin >> K >> N;
  cout << Solution().superEggDrop(K, N) << endl;
  return 0;
}
