/*
 * 有两种状态
 * 1. 最大圆盘在start处
 * 2. 最大圆盘在to处
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int state[60];
typedef long long LL;

#if 0
// the step from start to now
LL go(int n, int from, int mid, int to) {
  int cur = n;
  LL ans = 0;
  for (;cur >= 1 && state[cur] != mid; --cur) {
    if (state[cur] == from) {
      swap(mid, to);
    } else {
      // [Notice] must be 1L
      ans += (1L << (cur-1));
      swap(mid, from);
    }
  }
  return cur == 0 ? ans : -1;
}
#else
LL go(int n, int from, int mid, int to) {
  int k = state[n];
  if (k == mid) return -1;
  if (n == 1) {
    if (k == from) return 0;
    return 1;
  }
  if (k == from) {
    // from -> mid
    return go(n - 1, from, to, mid);
  }
  // k == to
  // mid -> to
  LL step = go(n-1, mid, from, to);
  if (step < 0) return -1;
  return (1L << (n - 1)) + step; 
}
#endif

int main() {
  int n, m;
  int height = 0;
  for (int r = 0; r < 3; ++r) {
    scanf("%d", &n);
    height += n;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &m);
      state[m] = r;
    }
  }
  LL step = go(height, 0, 1, 2);
  if (step < 0) printf("No\n");
  else {
    step = (1L << height) - 1 - step;
    printf("%lld\n", step);
  }
  return 0;
}

