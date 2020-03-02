// 可以直接用三个变量表示状态，就不需要下标
class Solution {
public:
    int waysToStep(int n) {
        if (n <= 2) return n;
        int dp[3] = {1, 1, 2}; // 注意dp[0]的初值是1,不是0！！！
        const int MOD = 1000000007;
        for (int i = 3; i <= n; ++i) {
            int cur = i % 3; // three
            int one = (i + 2) % 3;
            int two = (i + 1) % 3;
            dp[cur] = ((dp[cur] + dp[one]) % MOD + dp[two]) % MOD;
        }
        return dp[n % 3];
    }
};
