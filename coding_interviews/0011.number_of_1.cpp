#include "common.h"

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

int main() {
  int n;
  cin >> n;
  cout << Solution().NumberOf1(n) << endl;
  return 0;
}
