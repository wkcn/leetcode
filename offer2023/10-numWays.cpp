class Solution {
    const int MOD = 1000000007;
public:
    int numWays(int n) {
        // f(n) = f(n - 1) + f(n - 2)
        // f(1) = 1, f(2) = 2
        if (n == 0) return 1;
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int c = (a + b) % MOD;
            a = b; b = c;
        }
        return b;
    }
};
