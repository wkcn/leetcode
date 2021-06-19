#include "common.h"

int dp[101][101];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      // 可以发现, m和n都不大于100
      // 注意题目, 最多有m个0和n个1, 不是指刚好等于..
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
          dp[i][j] = 0;
        }
      }
      for (int k = 0; k < strs.size(); ++k) {
        pair<int, int> p = count(strs[k]);
        for (int i = m; i >= p.first; --i) {
          for (int j = n; j >= p.second; --j) {
            int v = dp[i - p.first][j - p.second]; 
            dp[i][j] = max(dp[i][j], v + 1);
          }
        }
      }
      return dp[m][n];
    }
    pair<int, int> count(string &s) {
      int zero = 0;
      for (char c : s) if (c == '0') ++zero;
      return {zero, s.size() - zero};
    }
};

int main() {
  {
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 3, n = 4;
    cout << Solution().findMaxForm(strs, m, n) << endl;
  }
  if (0) {
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << Solution().findMaxForm(strs, m, n) << endl;
  }
  if (0) {
    vector<string> strs{"10", "0", "1"};
    int m = 1, n = 1;
    cout << Solution().findMaxForm(strs, m, n) << endl;
  }
  return 0;
}
