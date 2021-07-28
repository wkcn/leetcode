class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n > m) return uniquePaths(n, m);
        vector<int> dp(n, 1);
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[c] = dp[c-1] + dp[c];
            }
        }
        return dp.back();
    }
};
