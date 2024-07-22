#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[101];
int C[101];
int DP[100001];
// 1 <= A <= 100000
// 1 <= C <= 1000
// m<=100000
bool solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 0) return false;
  for (int i = 0; i < n; ++i) scanf("%d", A + i);
  for (int i = 0; i < n; ++i) scanf("%d", C + i);
  memset(DP, -1, sizeof(DP));
  DP[0] = 0;
  for (int i = 0; i < n; ++i) {
    int a = A[i], c = C[i];
    for (int j = 0; j <= m; ++j) {
      if (DP[j] >= 0) {
        DP[j] = c;
      } else if (j >= a && DP[j - a] > 0) {
        DP[j] = DP[j - a] - 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    if (DP[i] >= 0) ++ans;
  }
  printf("%d\n", ans);
  return true;
}



int main() {
  while (solve()) {}
  return 0;
}
