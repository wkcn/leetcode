#include "common.h"

class Solution {
  public:
    int reverse(int x) {
      int res = 0;
      int r = x;
      if (r < 0) r = -r;
      bool neg = (x < 0);
      do {
        if (res > INT_MAX / 10) return 0;
        res *= 10;
        res += r % 10;
        if (res < 0) return 0;
        r /= 10;
      } while (r != 0);
      if (neg) res = -res;
      return res;
    }
};

int main() {
  Solution so;
  int u;
  while (cin >> u) {
  cout << so.reverse(u) << endl;
  }
  return 0;
}
