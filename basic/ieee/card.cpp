#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

ULL dp[10010 + 1010];
ULL cost[10010 + 1010];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%llu", cost + i);
  dp[0] = 0;
  for (int i = 1; i <= n + k; ++i) {
    dp[i] = UINT64_MAX;//dp[i-1] + (i <= n ? cost[i]:0L);
    // for (int t = 1; t <= k; ++t) {
    if (1) {
      int t = k;
      int u = i - 2 * t - 1;
      // 在i-t的位置翻牌
      if (i - t >= 1 && i - t <= n) {
        if (u >= 0) {
          if (dp[u] != UINT64_MAX) {
            dp[i] = min(dp[i], dp[u] + cost[i - t]);
          }
        } else {
            dp[i] = min(dp[i], cost[i - t]);
        }
      }
    }
  }
  /*
  for (int i = 1; i <= n + k; ++i) {
    cout << dp[i] << "=======" << endl;
  }
  */
  /*
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + cost[i];
    for (int t = 1; t <= k; ++t) {
      int u = i - 2 * t - 1;
      dp[i] = min(dp[i], (u>=0?dp[u]:0) + cost[i - t]); 
    }
  }
  for (int i = n + 1; i <= n + k; ++i) {
    dp[i] = UINT64_MAX;
    for (int t = i - n; t <= k; ++t) {
      int u = i - 2 * t - 1;
      dp[i] = min(dp[i], (u>=0?dp[u]:0) + cost[i - t]); 
    }
  }
  */
  ULL best = dp[n];
  for (int t = 1; t <= k; ++t) best = min(best, dp[n+t]);
  printf("%llu\n", best);
  return 0;
}
