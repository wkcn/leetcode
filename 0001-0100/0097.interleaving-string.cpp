// TODO: 滚动数组
#include "common.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int len1 = s1.size();
        const int len2 = s2.size();
        // 注意比较长度！！
        if (len1 + len2 != s3.size()) return false;
        // dp[i][j] 代表s1[:i]和s2[:j]能够交错组成s3[:i+j]
        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
        // 设置初值
        dp[0][0] = true;
        for (int i = 0; i < len1; ++i) {
          if (s1[i] != s3[i]) break;
          dp[i+1][0] = true;
        }
        for (int i = 0; i < len2; ++i) {
          if (s2[i] != s3[i]) break;
          dp[0][i+1] = true;
        }
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                // 更新dp[i+1][j+1]
                // 注意s3的下标
                char c = s3[i+j+1];
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == c) ||
                    (dp[i+1][j] && s2[j] == c);
            }
        }
        return dp.back().back();
    }
};

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout << Solution().isInterleave(s1, s2, s3) << endl;
  return 0;
}
