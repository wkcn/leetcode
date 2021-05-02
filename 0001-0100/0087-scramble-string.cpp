// 很好的动态规划题目
#include "common.h"

bool dp[31][31][31];  // dp[len][i][j], 长度为len时, s1[i:i + len]能变换为s2[j:j + len]
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 注意, 循环迭代时, 是在子字符串的基础上进行的
        /*
        假设s的子串被分成了s[i:j], s[j:k]
        对应t的子串被分为了t[i:j], t[j:k]
        有s[i:j] == t[i:j] && s[j:k] == t[j:k]
        或者s[i:j] == t[i + (k-j):k] && s[j:k] == t[i:i + (k-j)]
         */
        if (s1.size() != s2.size()) return false;
        const int len = s1.size();
        // when len == 1
        for (int i = 0; i < len; ++i) {
          for (int j = 0; j < len; ++j) {
            dp[1][i][j] = s1[i] == s2[j];
          }
        } 
        for (int l = 2; l <= len; ++l) {
          // 下面允许等于
          for (int i = 0; i <= len - l; ++i) {
            for (int j = 0; j <= len - l; ++j) {
              bool matched = false;
              for (int left = 1; left < l; ++left) {
                const int right = l - left;
                // 注意算子优先级
                // 如果没有互换
                if (matched = (dp[left][i][j] && dp[right][i + left][j + left])) break;
                // 如果互换
                if (matched = (dp[left][i][j+right] && dp[right][i + left][j])) break;
              }
              dp[l][i][j] = matched;
            }
          }
        }
        return dp[len][0][0];
    }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << Solution().isScramble(s1, s2) << endl;
  return 0;
}
