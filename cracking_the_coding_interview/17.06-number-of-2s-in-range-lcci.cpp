#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
// 注意范围啊
using LL = long long;
class Solution {
public:
    int numberOf2sInRange(int n) {
        // 考虑每一位为2的次数
        // 记当前位的高位有a种(包括0), 低位有b种(满0~99)
        /*
        如果当前位 > 2, a * b
        如果当前位 < 2, (a - 1) * b
        如果当前位 == 2, 如1324, (a - 1) * b + 末尾 + 1
        */
        int cnt = 0;
        LL b = 1;
        int m = 0;
        while (n > 0) {
            int v = n % 10;
            n /= 10;
            // n + 1 是 a
            if (v > 2) cnt += (n + 1) * b;
            else if (v < 2) cnt += n * b;
            else cnt += n * b + m + 1;
            // 注意顺序, v是高位
            m = m + v * b;
            b *= 10;
        }
        return cnt;
    }
};
#elif SOLUTION == 2

// DP
class Solution {
public:
    int numberOf2sInRange(int n) {
      /*
       * 从低位到高位
       * 只有取当前位最大值时, 才会受后面的数字影响, 因此我们将最大值特殊处理
       * 上一位为2的数量
       * 假如当前数字为vxy
       * 如果当前位v > 2, 
       *             v * numberOf2sInRange(99) + 100 + numberOf2sInRange(xy)
       *           v == 2,
       *             2 * numberOf2sInRange(99) + numberOf2sInRange(xy) + (xy + 1)
       *           v == 1
       *             numberOf2sInRange(99) + numberOf2sInRange(xy)
       *           v == 0
       *             numberOf2sInRange(xy)
       */
      using LL = long long;
      // 用最低一位初始化
      LL nine = 1;
      int xy = n % 10;
      LL base = 10;
      // 设置初值
      int nxy = xy < 2 ? 0 : 1;
      n /= 10;
      while (n > 0) {
        int v = n % 10;
        if (v < 2) {
          nxy = (v * nine + nxy);
        } else if (v == 2) {
          nxy = 2 * nine + nxy + (xy + 1);
        } else {
          // v > 2
          nxy = v * nine + base + nxy; 
        }
        n /= 10;
        xy += base * v;
        nine = 10 * nine + base;
        base *= 10;
      }
      return nxy;
    }
};

#endif

int main() {
  int n;
  cin >> n;
  cout << Solution().numberOf2sInRange(n) << endl;
  return 0;
}
