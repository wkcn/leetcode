#include "common.h"

// 逐步做优化！还可以在连续内存上优化！
// 处理好边界条件！！
// TODO: 不要用allows数组；并且使用滚动数组
// 暴力枚举法？
#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool isMatch(string s, string p) {
        // 需要用一个变量来处理特殊情况*
        const int slen = s.size(), plen = p.size();
        // 记得+1
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1));
        // 初始化dp[0][0], dp[0][j + 1]和dp[i + 1][0]
        dp[0][0] = true;
        int i, j;
        for (j = 0; j < plen; ++j) {
          if (p[j] == '*') dp[0][j + 1] = true;
          else break;
        }
        for (; j < plen; ++j) dp[0][j + 1] = false;
        for (i = 0; i < slen; ++i) dp[i + 1][0] = false;
        // 需要处理好dp的初值
        // 注意两个循环的顺序
        // 注意，*号可以匹配0个或多个
        // 对于*号的情况，dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j] || dp[i-1][j] || ... || dp[1][j] || dp[0][j], 只有i在变
        /* Naive
        for (i = 0; i < slen; ++i) {
          for (j = 0; j < plen; ++j) {
            bool allow = false;
            // 需要优化
            for (int k = 0; k <= i + 1; ++k) {
              if (dp[k][j]) allow = true;
            } 
            dp[i + 1][j + 1] = (dp[i][j] && (s[i] == p[j] || p[j] == '?')) || (p[j] == '*' && allow);
          }
        }
        */
        /*
        // 改循环顺序，将vector移出来
        for (j = 0; j < plen; ++j) {
          vector<bool> allows(slen);
          bool allow = false;
          for (int k = 0; k < slen; ++k) {
            if (dp[k][j]) allow = true;
            allows[k] = allow;
          } 
          for (i = 0; i < slen; ++i) {
            bool allow = false;
            dp[i + 1][j + 1] = (dp[i][j] && (s[i] == p[j] || p[j] == '?')) || (p[j] == '*' && allows[i]);
          }
        }
        */
        vector<bool> allows(slen);
        bool allow = false;
        for (int k = 0; k < slen; ++k) {
          if (dp[k][0]) allow = true;
          allows[k] = allow;
        } 
        for (j = 0; j < plen; ++j) {
          vector<bool> new_allows(slen);
          bool allow = false;
          for (i = 0; i < slen; ++i) {
            dp[i + 1][j + 1] = (dp[i][j] && (s[i] == p[j] || p[j] == '?')) || (p[j] == '*' && allows[i]);
            if (dp[i + 1][j + 1]) allow = true;
            new_allows[i] = allow;
          }
          allows = std::move(new_allows);
        }
        return dp[slen][plen];
    }
};
#elif SOLUTION == 2

class Solution {
public:
    bool isMatch(string s, string p) {
        // 需要用一个变量来处理特殊情况*
        const int slen = s.size(), plen = p.size();
        // 记得+1
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1));
        // 初始化dp[0][0], dp[0][j + 1]和dp[i + 1][0]
        dp[0][0] = true;
        int i, j;
        for (j = 0; j < plen; ++j) {
          if (p[j] == '*') dp[0][j + 1] = true;
          else break;
        }
        for (; j < plen; ++j) dp[0][j + 1] = false;
        for (i = 0; i < slen; ++i) dp[i + 1][0] = false;
        for (int i = 0; i < slen; ++i) {
          for (int j = 0; j < plen; ++j) {
            // 注意这里对*的处理, 用于匹配0到1+个的处理方法！
            dp[i + 1][j + 1] = (dp[i][j] && (s[i] == p[j] || p[j] == '?')) || (p[j] == '*' &&
                (dp[i][j + 1] || dp[i + 1][j]));
          }
        }
        return dp[slen][plen];
    }
};

#endif

int main() {
  string s, p;
  cin >> s >> p;
  cout << Solution().isMatch(s, p) << endl;
  return 0;
}
