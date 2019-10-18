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

#endif

int main() {
  double base;
  int exponent;
  cin >> base >> exponent;
  cout << Solution().Power(base, exponent) << endl;
  return 0;
}
