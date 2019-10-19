#include "common.h"

#if 0

class Solution {
public:
  double Power(double base, int exponent) {
    if (exponent == 0) return 1;
    bool inv = exponent < 0;
    if (inv) exponent = -exponent;
    double res = exponent & 1 ? base * Power(base*base, exponent/2) : Power(base*base, exponent/2);
    return inv ? 1.0 / res : res;
  }
};

#else

#if 0

class Solution {
public:
  double Power(double base, int exponent) {
    bool inv = exponent < 0;
    if (inv) exponent = -exponent;
    double res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= base;
      base *= base;
      exponent >>= 1;
    }
    return inv ? 1.0 / res : res;
  }
};

#else

// we should consider the case when exponent is INT32_MIN
class Solution {
public:
  double Power(double base, int exponent) {
    double res = 1;
    if (exponent < 0) base = 1 / base;
    while (exponent != 0) {
      if (exponent & 1) res *= base;
      base *= base;
      exponent /= 2;
    }
    return res;
  }
};

#endif

#endif

int main() {
  double base;
  int exponent;
  cin >> base >> exponent;
  cout << Solution().Power(base, exponent) << endl;
  return 0;
}
