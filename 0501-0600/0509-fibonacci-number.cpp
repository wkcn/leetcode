#include "common.h"

using mat22 = array<array<int, 2>, 2>;
using v1_t = array<int, 2>;
class Solution {
public:
    int fib(int n) {
      /*
       * [F(n+1), F(n)]^T = [[1, 1], [1, 0]] [F(n), F(n-1)]^T
       *
       * [F(1), F(0)] = [1, 0]
       */
      if (n < 2) return n;
      mat22 m{v1_t{1, 1}, v1_t{1, 0}};
      mat22 y = power(m, n - 1); 
      return y[0][0];
    }
    mat22 power(const mat22 &m, int n) {
      if (n == 0) return {v1_t{1, 0}, v1_t{0, 1}};
      if (n == 1) return m;
      int half = n / 2;
      mat22 mh = power(m, half);
      mat22 mm = mul(mh, mh);
      if (n % 2) mm = mul(mm, m);
      return mm;
    }
    mat22 mul(const mat22 &a, const mat22 &b) {
      mat22 out{v1_t{0, 0}, v1_t{0, 0}};
      #pragma unroll
      for (int r = 0; r < 2; ++r) {
        #pragma unroll
        for (int k = 0; k < 2; ++k) {
          #pragma unroll
          for (int c = 0; c < 2; ++c) {
            out[r][c] += a[r][k] * b[k][c]; 
          }
        }
      }
      return out;
    }
};

int main() {
  for (int i = 0; i < 10; ++i)
    cout << i << ": " << Solution().fib(i) << endl;
  return 0;
}
