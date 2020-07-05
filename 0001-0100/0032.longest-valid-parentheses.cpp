// 好题目!
#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    int longestValidParentheses(string s) {
        // (()
        // -1
        // -1, 0
        stack<int> st;
        st.push(-1);  // 类似哨兵节点
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop(); // pop上一个左括号
                if (st.empty()) {
                    // 没有左括号为其匹配
                    st.push(i);
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int longestValidParentheses(string s) {
      if (s.empty()) return 0;
      vector<int> dp(s.size() + 1);
      dp[0] = 0;
      dp[1] = 0;
      // 左闭右开，dp[0]作为哨兵 
      int best = 0;
      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == ')') {
          if (s[i - 1] == '(') {
            dp[i + 1] = dp[i - 1] + 2;
            best = max(best, dp[i + 1]);
          } else {
            // ))的情况
            int k = i - dp[i] - 1;
            if (k >= 0 && s[k] == '(') {
              // 注意这里，dp[i]可能不能与前面的匹配，如()(())
              dp[i + 1] = dp[k] + dp[i] + 2;
              best = max(best, dp[i + 1]);
            } else {
              dp[i + 1] = 0;
            }
          } 
        }
      }
      return best;
    }
};

#elif SOLUTION == 3

class Solution {
public:
    int longestValidParentheses(string s) {
      int left = 0, right = 0;
      int best = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') ++left;
        else {
          ++right;
          if (right == left) {
            best = max(best, left * 2);
          } else {
            if (right > left) {
              left = 0;
              right = 0;
            } 
          }
        }
      }
      left = 0, right = 0;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ')') ++left;
        else {
          ++right;
          if (right == left) {
            best = max(best, left * 2);
          } else {
            if (right > left) {
              left = 0;
              right = 0;
            } 
          }
        }
      }
      return best;
    }
};

#endif

int main() {
  string s;
  cin >> s;
  cout << Solution().longestValidParentheses(s) << endl;
  return 0;
}
