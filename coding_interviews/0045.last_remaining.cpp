#include "common.h"

class Solution {
public:
  int LastRemaining_Solution(int n, int m) {
    // f(1) = 0
    // f(n) = (f(n-1) + m) % n
    if (n == 0) return -1;
    int v = 0;
    for (int k = 2; k <= n; ++k) {
      v = (v + m) % k;
    }
    return v;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  cout << Solution().LastRemaining_Solution(n, m) << endl;
  return 0;
}
