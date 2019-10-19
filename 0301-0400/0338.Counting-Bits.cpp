/*
 * https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
 * 数字的进位对1的个数有较大影响
 * 假如没有发生进位，1的数量增加1
 * 受到进位影响的bit会从0到1, 或从1到0
 * n & (n-1)能得到不受进位影响的bit
 * 从右到左第一个从0变为1的位置
 */
#include "common.h"

class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> ans(num + 1, 0);
      for (int i = 1; i <= num; ++i) {
        #if 0
        ans[i] = ans[i & (i-1)] + 1;
        #else
        ans[i] = ans[i >> 1] + (i & 1);
        #endif
      }
      return ans;
    }
};

int main() {
  for (int i = 0; i < 16; ++i) {
    cout << i << ": \t";
    int z = 1 << 7;
    do {
      putchar(bool(z & i) + '0');
      z >>= 1;
    } while (z > 0);
    putchar('\n');
  }

  int num;
  cin >> num;
  PRINT_ARRAY(Solution().countBits(num));
  return 0;
}
