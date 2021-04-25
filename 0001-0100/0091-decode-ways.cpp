#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1

class Solution {
public:
    int numDecodings(string s) {
      // 写完后发现第一句是可以删去的
      // if (s.empty() || (s[0] == '0')) return 0;
      const int len = s.size();
      vector<unsigned int> dp(len + 1);
      dp[0] = 1;
      for (int i = 0; i < len; ++i) {
        // 0不能单独解码
        // 这样可以避开1301, 因为0后面的一个数不能跟着前面的0, 也不能和0组合
        if (s[i] != '0')
          dp[i + 1] = dp[i];
        if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
          // 两个数字为一个解码
          dp[i + 1] += dp[i - 1];
        }
      }
      return dp[len];
    }
};

#elif SOLUTION == 2

class Solution {
public:
    int numDecodings(string s) {
      // 写完后发现第一句是可以删去的
      // if (s.empty() || (s[0] == '0')) return 0;
      const int len = s.size();
      int pre = 0;
      int cur = 1;
      for (int i = 0; i < len; ++i) {
        // 0不能单独解码
        // 这样可以避开1301, 因为0后面的一个数不能跟着前面的0, 也不能和0组合
        int next = 0;
        if (s[i] != '0')
          next += cur;
        if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
          // 两个数字为一个解码
          next += pre;
        }
        pre = cur;
        cur = next;
      }
      return cur;
    }
};

#endif

int main() {
  string s; cin >> s;
  cout << Solution().numDecodings(s) << endl;
  return 0;
}
