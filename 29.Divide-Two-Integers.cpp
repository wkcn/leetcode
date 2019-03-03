#include "common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
      if (divisor == 1) return dividend;
      if (divisor == -1) {
        if (dividend == INT32_MIN) return INT32_MAX;
        return -dividend;
      }
      if (divisor == INT32_MIN) {
        switch (dividend) {
          case INT32_MIN: return 1;
          default: return 0;
        }
      }
      // dividend / divisor
      bool minus = (dividend < 0) ^ (divisor < 0);

      // let dividend be negative to store more digits
      if (dividend > 0)
        dividend = -dividend;

      if (divisor < 0)
        divisor = -divisor;

      int res = 0;
      int u = 1;

      while (dividend <= -divisor) {
        dividend += divisor;
        res += u;
        if (divisor & (1<<30)) break; // divisor will be overflow
        divisor <<= 1;
        u <<= 1;
      }
      while (divisor > 0) {
        if (dividend <= -divisor) {
          dividend += divisor;
          res += u;
        }
        divisor >>= 1;
        u >>= 1;
      }

      return minus ? -res : res;
    }
};

int main() {
  int a = -1;
  printf("%x\n", a);
  printf("%x\n", INT32_MIN);
  printf("%x\n", INT32_MAX);
  printf("%x\n", -2137325331);
  cout << 10 / 3 << endl;
  cout << 10 / (-3) << endl;
  int b;
  cin >> a >> b;
  cout << Solution().divide(a, b) << endl;
  return 0;
}
