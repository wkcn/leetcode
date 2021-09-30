#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        /*
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[n1][n2];
        */
        if (n1 < n2) return minDistance(word2, word1);
        vector<int> dp(n2 + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 0; i < n1; ++i) {
            // set left-top value and dp[0]
            int lt = i;
            dp[0] = i + 1;
            for (int j = 0; j < n2; ++j) {
                int old = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = lt;
                } else {
                    dp[j + 1] = min(dp[j], dp[j + 1]) + 1;
                }
                lt = old;
            }
        }
        return dp.back();
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 < n2) return minDistance(word2, word1);
        vector<int> dp(n2 + 1, 0);
        // 先求最长公共子序列
        for (int i = 0; i < n1; ++i) {
            dp[0] = 0;
            int lt = 0;
            for (int j = 0; j < n2; ++j) {
                // compute dp[i + 1][j + 1]
                int old = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = lt + 1;
                } else {
                    dp[j + 1] = max(dp[j], dp[j + 1]);
                }
                lt = old;
            }
        }
        return n1 + n2 - dp.back() * 2;
    }
};
#endif

int main() {
  string a = "a";
  string b = "b";
  cout << Solution().minDistance(a, b) << endl;
  return 0;
}
