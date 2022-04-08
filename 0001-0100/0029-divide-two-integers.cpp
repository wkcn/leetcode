#include "common.h"

class Solution {
public:
  int divide(int dividend, int divisor) {
    // if overflow, return 2^31 - 1
    // divisor != 0
    if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
    if (dividend == 0) return 0;  // will be removed
    bool minus = (dividend > 0) ^ (divisor > 0);
    if (dividend > 0) dividend = -dividend;
    if (divisor > 0) divisor = -divisor;
    int max_divisor = divisor;
    int r = -1;
    while (max_divisor >= -(INT32_MAX >> 1) - 1 && max_divisor * 2 >= dividend) {
      r *= 2;
      max_divisor *= 2;
    }
    int ans = 0;
    while (dividend < 0) {
      while (dividend <= max_divisor) {
        dividend -= max_divisor;
        ans += r;
      }
      max_divisor = max_divisor != INT32_MIN ? -((-max_divisor) >> 1) : -(INT32_MAX >> 1) - 1;
      r = r != INT32_MIN ? -((-r) >> 1) : -(INT32_MAX >> 1) - 1;
    }
    if (minus) return ans;
    return -ans;
  }
};

int main() {
  int a, b;
  while (1) {
    cin >> a >> b;
    cout << Solution().divide(a, b) << endl;
  }
  return 0;
}
