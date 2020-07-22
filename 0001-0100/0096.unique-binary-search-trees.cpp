// TODO: 使用数学方法卡塔兰数能在O(n)时间复杂度内算出结果
class Solution {
public:
    int numTrees(int n) {
        // dp[n] = sum_k (dp[k] * dp[n - k - 1])
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int z = 0;
            for (int k = 0; k < i; ++k) {
                z += dp[k] * dp[i - k - 1];
            }
            dp[i] = z;
        }
        return dp.back();
    }
};
