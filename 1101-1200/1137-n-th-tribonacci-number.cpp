#include "common.h"

using mat33 = array<array<int, 3>, 3>;
using v1_t = array<int, 3>;
class Solution {
public:
    int tribonacci(int n) {
      /*
       * [F(n+2), F(n+1), F(n)]^T = [[1, 1, 1], [1, 0, 0], (0, 1, 0)] [F(n+1), F(n), F(n-1)]^T
       *
       * [F(2), F(1), F(0)] = [1, 1, 0]
       */
      if (n == 0) return 0;
      if (n <= 2) return 1;
      mat33 m{v1_t{1, 1, 1}, v1_t{1, 0, 0}, v1_t{0, 1, 0}};
      mat33 y = power(m, n - 2); 
      return y[0][0] + y[0][1];
    }
    mat33 power(const mat33 &m, int n) {
      if (n == 0) return {v1_t{1, 0, 0}, v1_t{0, 1, 0}, v1_t{0, 0, 1}};
      if (n == 1) return m;
      int half = n / 2;
      mat33 mh = power(m, half);
      mat33 mm = mul(mh, mh);
      if (n % 2) mm = mul(mm, m);
      return mm;
    }
    mat33 mul(const mat33 &a, const mat33 &b) {
      mat33 out{v1_t{0, 0, 0}, v1_t{0, 0, 0}, v1_t{0, 0, 0}};
      #pragma unroll
      for (int r = 0; r < 3; ++r) {
        #pragma unroll
        for (int k = 0; k < 3; ++k) {
          #pragma unroll
          for (int c = 0; c < 3; ++c) {
            out[r][c] += a[r][k] * b[k][c]; 
          }
        }
      }
      return out;
    }
};

int main() {
  for (int i = 0; i < 30; ++i)
    cout << i << ": " << Solution().tribonacci(i) << endl;
  return 0;
}
