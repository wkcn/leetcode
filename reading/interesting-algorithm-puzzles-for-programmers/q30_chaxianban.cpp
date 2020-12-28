// 很好的题目！
// 如果考虑插的位置，应该怎么改？
/*
 * 对工程师而言，确保电源是最重要的事情。不仅是 PC，当智能手机、平板电脑、数码相机等电量不足时，我们也肯定要四处寻找插座。不过，多人共用的时候就必须共享插座，这时插线板就会派上用场。一般的插线板除了有延长线，还会有多个插口。

这里假设有双插口和三插口的插线板。墙壁上只有 1 个插座能用，而需要用电的电器有 n 台，试考虑此时应如何分配插线板。举个例子，当 n＝ 4 时，如 图 21 所示，有 4 种插线板插线方法（使用同一个插线板时，不考虑插口位置，只考虑插线板的连接方法。另外，要使插线板上最后没有多余的插口）。

作者：图灵教育
链接：https://leetcode-cn.com/leetbook/read/interesting-algorithm-puzzles-for-programmers/9l2pjv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#include "common.h"

// 有双插口和三插口插线版
// 看成二叉树，三叉树，看根节点数量
// 不考虑插的位置
typedef long long LL;
LL solve(int n) {
  if (n <= 0) return 0;
  if (n <= 2) return 1;
  vector<LL> dp(n + 1);
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  // 要求a <= b <= c, 且要注意相等的情况
  for (int i = 4; i <= n; ++i) {
    LL cnt = 0;
    // 两插孔
    for (int a = 1; a <= i / 2; ++a) {
      int b = i - a;
      /*
       * if i == 4
       * a, b = (1, 3), (2, 2)
       */
      if (a == b) {
        LL k = dp[a];
        // 从k中选出一个结构重复两遍，或者从k中选出两个结构
        cnt += k + k * (k - 1) / 2;
      } else {
        cnt += dp[a] * dp[b];
      }
    }
    for (int a = 1; a <= i / 3; ++a) {
      for (int b = a; b <= (i - a) / 2; ++b) {
        int c = i - a - b;
        // a <= b <= c
        // 可以分为：
        // a < b < c
        // a == b < c
        // a < b == c
        // a == b == c
        if (a < b && b < c) {
          cnt += dp[a] * dp[b] * dp[c];
        } else if (a == b && b < c) {
          LL k = dp[a];
          cnt += (k + k * (k - 1) / 2) * dp[c];
        } else if (a < b && b == c) {
          LL k = dp[b];
          cnt += (k + k * (k - 1) / 2) * dp[a];
        } else {
          // a == b == c
          // 选三个不同的结构
          LL k = dp[a];
          cnt += k * (k - 1) * (k - 2) / 6;
          // 仅有两个相同
          cnt += k * (k - 1);
          // 三个都相同
          cnt += k;
        }
      }
    }
    dp[i] = cnt;
  }
  return dp.back();
}

int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
