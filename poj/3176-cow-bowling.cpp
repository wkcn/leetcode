#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[351];

int main() {
  int n;
  scanf("%d", &n);
  DP[0] = 0;
  for (int r = 0; r < n; ++r) {
    int prev = -10000;
    for (int c = 0; c <= r; ++c) {
      int x;
      scanf("%d", &x);
      int old = DP[c];
      DP[c] = max(DP[c], prev) + x;
      prev = old;
    }
  }
  int ans = *max_element(DP, DP+n);
  printf("%d\n", ans);
  return 0;
}
