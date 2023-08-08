class Solution {
public:
    vector<double> dicesProbability(int n) {
        if (n == 0) return {};
        int su = n * 6;
        vector<int> dp(su + 1);
        for (int i = 1; i <= 6; ++i) dp[i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = su; j >= 1; --j) {
                // 要清空状态
                dp[j] = 0;
                for (int d = 1; d <= 6 && j - d >= 0; ++d) {
                    dp[j] += dp[j - d];
                }
            }
        }

        vector<double> ans;
        double b = pow(6.0, n);
        for (int i = n; i <= su; ++i) {
            ans.push_back(dp[i] / b);
        }
        return ans;
    }
};
