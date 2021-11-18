#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
int record[32][2][2];
class Solution {
public:
    int findIntegers(int n) {
      // 分为满二叉树和不满两种情况
      // 状态：(上一个点是否为1, 当前bit位置，是否受到当前bit的限制)
      for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            record[i][j][k] = -1;
          }
        }
      }
      vector<int> buf;
      function<int(bool, int, bool)> F = [&](bool last_is_one, int i, bool limit) -> int {
        if (i == 0) {
          if (!last_is_one && ((n & 1) || !limit)) {
            return 2;
          }
          return 1;
        }
        auto &rv = record[i][last_is_one][limit];
        if (rv != -1) return rv;
        bool one = (unsigned int)n & ((unsigned int)1 << i); 
        // 0
        int ans = F(false, i - 1, limit && !one);
        // 1
        if (!last_is_one) {
          if (one || !limit) {
            ans += F(true, i - 1, limit && one);
          }
        }
        rv = ans;
        return ans;
      };
      return F(false, 31, true);
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int findIntegers(int n) {
      // 先统计以0为根节点，深度为d, 满二叉树的个数
      // dp[0] = 1是为了让dp[2] = 2
      dp[0] = 1; dp[1] = 1;
      for (int i = 2; i <= 32; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }

      int ans = 0;
      bool last_is_one = false;
      for (int i = 31; i >= 0; --i) {
        // 每次都是看非满二叉树这边，满二叉树的早就计算了
        bool one = ((unsigned int)n & ((unsigned int)1 << i));
        if (one) {
          // 0开头可以是满二叉树
          ans += dp[i + 1];
          if (last_is_one) {
            break;
          }
        }
        if (i == 0) {
          ans += 1;
        }
        last_is_one = one;
      }
      return ans;
    }
private:
    int dp[33];
};
#endif

int main() {
  for (int i = 0; i < 10; ++i) {
    cout << i << ": " << Solution().findIntegers(i) << endl;
  }
  return 0;
}
