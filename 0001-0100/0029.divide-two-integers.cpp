#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 1) return dividend;
    if (divisor == -1) {
      if (dividend == INT32_MIN) return INT32_MAX;
      return -dividend;
    }
    bool minus = false;
    if (dividend > 0) {
      dividend = -dividend;
      minus = !minus;
    }
    if (divisor > 0) {
      divisor = -divisor;
      minus = !minus;
    }
    // 不能用二分法，因为不能用除法判断乘法是否越界
    vector<int> vs;
    while (divisor >= dividend) {
      vs.push_back(divisor);
      if (divisor < -(INT32_MAX >> 1)) break;
      divisor *= 2;
    }
    if (vs.empty()) return 0;
    int ans = 0;
    int r = 1 << (vs.size() - 1);
    while (!vs.empty()) {
      const int v = vs.back(); vs.pop_back();
      while (dividend <= v) {
        ans += r;
        dividend -= v;
      }
      r >>= 1;
    }
    if (minus) ans = -ans;
    return ans;
  }
};

#elif SOLUTION == 2

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 1) return dividend;
    if (divisor == -1) {
      if (dividend == INT32_MIN) return INT32_MAX;
      return -dividend;
    }
    bool minus = false;
    if (dividend > 0) {
      dividend = -dividend;
      minus = !minus;
    }
    if (divisor > 0) {
      divisor = -divisor;
      minus = !minus;
    }
    int ans = 0;
    while (dividend <= divisor) {
      int r = 1;
      int d = divisor;
      while (dividend <= d) {
        ans += r;
        dividend -= d;
        if (d < INT32_MIN - d) break;
        d += d;
        r += r;
      }
    }
    return minus ? -ans : ans;
  }
};

#endif

int main() {
  int dividend, divisor;
  cin >> dividend >> divisor;

  cout << Solution().divide(dividend, divisor) << endl;
  return 0;
}
