#include "common.h"

#if 0
class Solution {
public:
   int NumberOf1(int n) {
     int m = 0;
     while (n != 0) {
       n &= n - 1;
       ++m;
     }
     return m;
   }
};
#else

class Solution {
public:
   int NumberOf1(int n) {
     int m = 0;
     if (n < 0) {
       if (n == 0x80000000) return 1;
       n = 0x7FFFFFFF - (-n) + 1;
       ++m; // sign
     }
     while (n != 0) {
       if (n % 2) ++m;
       n /= 2;
     }
     return m;
   }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().NumberOf1(n) << endl;
  return 0;
}
