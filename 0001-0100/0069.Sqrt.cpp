#include "common.h"

class Solution {
public:
  int mySqrt(int x) {
    // x <= target | [lo, hi) | target < x
    // upper_bound
    int lo = 1, hi = x / 2 + 2; // sqrt(x) is in [lo, hi)
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      mid <= x / mid ? lo = mid + 1: hi = mid;
    }
    return --hi;
  }
};

int main() {
  Solution so;
  while (1) {
    int x;
    cin >> x;
    cout << so.mySqrt(x) << endl;
  }
  return 0;
}
