#include "common.h"

class Solution {
public:
  int NumberOf1Between1AndN_Solution(int n) {
    int res = 0;
    for (int i = 1; i <= n; i *= 10) {
      int a = n / i, b = n % i;
      // n = 3456, i = 100, a = 34, b = 56, x = a % 10, a > 0
      // if x == 0, (a / 10) * i 
      // if x == 1, (a / 10) * i + b + 1
      // if x > 1, (a / 10 + 1) * i
      /*
      int x = a % 10;
      res += (a / 10) * i + (x == 1) * (b + 1) + (x > 1) * (i);
      */
      res += ((a + 8)/ 10) * i + (a % 10 == 1) * (b + 1);
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().NumberOf1Between1AndN_Solution(n) << endl;
  return 0;
}
