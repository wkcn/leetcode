#include "common.h"

class Solution {
public:
    string smallestGoodBase(string n) {
      /*
        乘上k进制后
        有(k - 1) * n + 1 = k^(r - 1), r >= 1, k >= 2
        求最小的整数k
       */
      // k 越小, 位数m越大
      long long v_n = stoll(n);
      long long min_k = v_n - 1;
      // m >= 2
      for (long long m = log(v_n) / log(2); m >= 2; --m) {
        long long k = pow(v_n, 1.0 / m); 
        long long an = 1, e = 1;
        for (int i = 0; i < m; ++i) {
          e *= k;  // 这里也可能溢出
          an += e;
        }
        if (an == v_n) min_k = min(min_k, k);
      }
      return to_string(min_k);
    }
};

int main() {
  while (1) {
    string n;
    // cin >> n;
    n = "14919921443713777";
    cout << Solution().smallestGoodBase(n) << endl;
    break;
  }
  return 0;
}
