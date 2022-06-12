#include "common.h"

class Solution {
public:
    int findNthDigit(int n) {
        // (9 - 1 + 1) * 1, (99 - 10 + 1) * 2, (999 - 100 + 1) * 3
        // 1. 确定位数
        int t = 1;
        int b = 1;
        --n;
        while (b <= INT32_MAX / 10) {
            // b * 10 may be overflow
            if (b * 10 - b > INT32_MAX / t) break;
            int u = (b * 10 - b) * t;
            if (n >= u) {
                n -= u;
                ++t;
                b *= 10;
            } else break;
        }
        // 2. 确定是第几个数字
        int e = n / t;
        // 3. 该数字的值
        e += b;
        return to_string(e)[n % t] - '0';
    }
};

int main() {
  while (1) {
    int n; cin >> n;
    cout << Solution().findNthDigit(n) << endl;
  }
  return 0;
}
