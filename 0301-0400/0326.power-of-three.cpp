// 模板元编程
#include "common.h"

typedef long long LL;

template <LL i>
struct G {
  static LL get() {
    return i;
  }
};

template <LL i, LL j>
struct F {
  static LL get() {
    return conditional<(i <= j / 3), F<i * 3, j>, G<i> >::type::get(); 
  }
};

const int MAX3P = F<1, INT32_MAX>::get();

class Solution {
public:
    bool isPowerOfThree(int n) {
      return n > 0 && MAX3P % n == 0;
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().isPowerOfThree(n) << endl;
  return 0;
}
