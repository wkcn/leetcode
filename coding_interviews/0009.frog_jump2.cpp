#include "common.h"

#if 0
class Solution {
public:
  int jumpFloorII(int number) {
    int su = 0;
    int cur = 0;
    while(number--) {
      cur = su + 1;
      su += cur;
    }
    return cur;
  }
};
#else

class Solution {
public:
  /*
   * f(1)   = 1
   * f(n)   = f(n-1) + f(n-2) + ... + f(1)
   * f(n-1) =          f(n-2) + ... + f(1)
   * f(n) - f(n-1) = f(n-1)
   * f(n) = 2 * f(n-1) = 2 ^ (n-1)
   */
  int jumpFloorII(int number) {
    return 1 << (number-1);
  }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().jumpFloorII(n) << endl;
  return 0;
}
