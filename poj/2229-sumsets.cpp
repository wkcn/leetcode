#include <cstdio>
#include <cstring>

int DP[1000001];
const int MOD = 1000000000;

#define SOLUTION 2

#if SOLUTION == 1
int main() {
  int n;
  scanf("%d", &n);
  memset(DP, 0, sizeof(DP));
  DP[0] = 1;
  for (int i = 1; i <= n; i *= 2) {
    for (int j = i; j <= n; ++j) {
      DP[j] = (DP[j] + DP[j - i]) % MOD;
    }
  }
  printf("%d\n", DP[n]);
  return 0;
}
#elif SOLUTION == 2

int main() {
  int n;
  scanf("%d", &n);
  memset(DP, 0, sizeof(DP));
  DP[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      DP[i] = DP[i - 1];
    } else {
      // 分别考虑序列中有1和无1
      DP[i] = (DP[i - 1] + DP[i / 2]) % MOD;
    }
  }
  printf("%d\n", DP[n]);
  return 0;
}

#endif
