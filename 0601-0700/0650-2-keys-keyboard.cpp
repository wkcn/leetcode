class Solution {
public:
    int minSteps(int n) {
        // DP: (当前A的数量，当前剪贴板中A的数量)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT32_MAX));
        dp[1][0] = 0; dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            int mv = INT32_MAX;
            for (int j = 1; j <= i / 2; ++j) {
                // i - j >= j
                // paste
                dp[i][j] = dp[i - j][j] != INT32_MAX ? dp[i - j][j] + 1 : INT32_MAX;
                mv = min(mv, dp[i][j]);
            }
            dp[i][i] = mv == INT32_MAX ? INT32_MAX : mv + 1;
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            // To assign dp[i]
            dp[i] = INT32_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j != 0) continue;
                int r = i / j;
                // j <= r <= i
                // because dp[i] is not assigned, when i == r
                dp[i] = min(dp[i], dp[j] + r);  // first assign to dp[i]
                dp[i] = min(dp[i], dp[r] + j);
            }
        }
        return dp[n];
    }
};
