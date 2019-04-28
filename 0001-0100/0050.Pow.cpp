#include "common.h"

#if 0
// 8 ms
class Solution {
public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      double res = 1;
      double base = n > 0 ? x : 1/x;
      if (n == INT32_MIN) {
        base = base * base;
        n = INT32_MIN / 2;
      }
      if (n < 0) n = -n;
      while (n > 0) {
        if (n & 1) res *= base;
        base = base * base;
        n >>= 1;
      }

      return res;
    }
};
#else
#if 0
// 4 ms
class Solution {
public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      double z = myPow(x, n / 2);
      if (n % 2) {
        return n > 0 ? x*z*z : (1.0 / x)*z*z;
      }
      return z*z;
    }
};
#else

// 4ms
class Solution {
public:
    double myPow(double x, int n) {
      double res = 1;
      double base = n > 0 ? x : 1.0 / x;
      if (n & 1) res = base;
      n /= 2;
      if (n == 0) return res;
      do {
        base = base * base;
        if (n & 1) res *= base;
        n /= 2;
      } while (n != 0);
      return res;
    }
};

#endif
#endif

int main() {
  Solution so;
  while (1) {
    double x; int n;
    cin >> x >> n;
    cout << so.myPow(x, n) << endl;
  }
  return 0;
}
