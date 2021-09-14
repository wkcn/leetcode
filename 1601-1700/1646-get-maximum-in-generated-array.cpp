class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i & 1) {
                dp[i] = dp[i >> 1] + dp[(i >> 1) + 1];
            } else {
                dp[i] = dp[i >> 1];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
