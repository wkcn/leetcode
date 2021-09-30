#include "common.h"

class Solution {
  using ULL = unsigned long long;
  using Mat = array<array<ULL, 2>, 2>;
  using V2 = array<ULL, 2>;
  const ULL MOD = ULL(1e9) + 7;
public:
  int fib(int n) {
    if (n <= 1) return n;
    Mat m{V2{1, 1}, V2{1, 0}};
    n -= 1;
    Mat r{V2{1, 0}, V2{0, 1}};
    while (n > 0) {
      if (n & 1) r = mul(r, m);
      m = mul(m, m);
      n >>= 1;
    }
    return r[0][0];
  }
  Mat mul(const Mat &a, const Mat &b) {
    Mat out{V2{0, 0}, V2{0, 0}};
    for (int r = 0; r < 2; ++r) {
      for (int k = 0; k < 2; ++k) {
        for (int c = 0; c < 2; ++c) {
          out[r][c] += (a[r][k] * b[k][c]) % MOD;
          out[r][c] %= MOD;
        }
      }
    }
    return out;
  }
};

int main() {
  for (int i = 0; i < 10; ++i) {
    cout << Solution().fib(i) << endl;
  }
  return 0;
}
