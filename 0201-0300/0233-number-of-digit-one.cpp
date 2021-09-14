#include "common.h"

class Solution {
public:
  int countDigitOne(int n) {
    /*
     * 假如n = 12345, 求3的位置中1出现的次数
     * 100, 101, 102, 103, ..., 199, 1100, 1101, ..., 12199
     * ans += (12 + 1) * 100
     * 假如n = 12045, 求0的位置中1出现的次数
     * 100, 101, 102, 103, ..., 199, 1100, 1101, ..., 11199
     * ans += 12 * 100
     * 假如n = 32145, 求1的位置中1出现的次数
     * 100, 101, ..., 199, 1100, 1101, ..., 1199, ..., 32100, ..., 32145
     *
     * n = 125, 求5的位置中1出现的次数
     * 1, 11, 21, 31, ..., 121
     * ans += (12 + 1) * 1
     * n = 120, 求5的位置中1出现的次数
     * 1, 11, 21, 31, ..., 111
     * ans += 12 * 1
     *
     * n = 10, 求0的位置中1出现的次数
     * 1
     * ans += 1 * 1
     * n = 10, 求1的位置中1出现的次数
     * 10
     */
    int ans = 0;
    int base = 1;
    int tail = 0;
    while (n > 0) {
      int y = n / 10;
      int r = n % 10;
      switch (r) {
        case 0:
          ans += y * base;
          break;
        case 1:
          ans += y * base + (tail + 1);
          break;
        default:
          ans += (1 + y) * base;
      };
      n = y;
      tail += r * base;
      if (INT32_MAX / 10 >= base) base *= 10;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  for (int i = 0; i < 30; ++i) {
    cout << i << ": " << sol.countDigitOne(i) << endl;
  }
  return 0;
}
