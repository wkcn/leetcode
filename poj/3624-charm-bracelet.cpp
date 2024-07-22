#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int W[3410];
int D[3410];
int DP[12881];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", W+i, D+i);
  }
  memset(DP, 0, sizeof(DP));
  // at most once
  for (int i = 0; i < n; ++i) {
    int w = W[i], d = D[i];
    for (int j = 0; j <= m - w; ++j) {
      DP[j] = max(DP[j], DP[j + w] + d);
    } 
  }
  int ans = DP[0];
  printf("%d\n", ans);
  return 0;
}
