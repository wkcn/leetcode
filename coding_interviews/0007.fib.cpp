#include "common.h"

class Solution {
public:
  int Fibonacci(int n) {
    if (n <= 1) return n;
    int a[2] = {0, 1};
    bool p = true;
    while(--n) {
      p = !p;
      a[p] += a[!p];
    };
    return a[p];
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().Fibonacci(n) << endl;
  return 0;
}
