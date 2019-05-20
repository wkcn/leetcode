#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>
using namespace std;

int best_cos[5000010];

int main() {
  int n;
  scanf("%d", &n);
  double ans = DBL_MIN;

  double max_cos = DBL_MIN;
  for (int d = 1; d <= n - 3; d += 2) {
    max_cos = max(max_cos, cos(d / 2.0));
    best_cos[d] = max_cos;
  }

  for (int x = 1; x <= n - 2; ++x) {
    int rest = n - x;
    // y + z = rest
    // sin(y) + sin(z) = 2sin((y+z)/2)cos((y-z)/2)
    double front = 2.0 * sin(rest / 2.0);
    double now;
    // * cos((y-z)/2)
    if (rest % 2 == 0) {
      // even
      now = sin(x) + front;
    } else {
      // rest is odd
      // 1 + (rest - 1) : rest - 2
      // 2 + (rest - 2) : rest - 4
      // (rest-1) + 1   : rest - 2
      // [1, rest-2]
      now = sin(x) + front * best_cos[rest - 2];
    }
    if (now > ans) ans = now; 
  }
  printf("%.9f\n", ans);
  return 0;
}
