/*
 * n & (n-1) 方法：
 * https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1)
 * https://leetcode.com/problems/number-of-1-bits/discuss/55120/Short-code-of-C%2B%2B-O(m)-by-time-m-is-the-count-of-1's-and-another-several-method-of-O(1)-time
 */
#include "common.h"

#if 0
class Solution {
public:
  int hammingWeight(uint32_t n) {
    uint32_t i = 1 << 31;
    int ans = 0;
    do {
      if (i & n) ++ans;
      i >>= 1;
    } while (i > 0);
    return ans;
  }
};
#else

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ++ans;
      n &= n - 1;
    }
    return ans;
  }
};

#endif

int main() {
  uint32_t n;
  cin >> n;
  cout << Solution().hammingWeight(n) << endl;
  return 0;
}
