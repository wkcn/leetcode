class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp;
        dp.push_back(1);
        int p3 = 0, p5 = 0, p7 = 0;
        while (--k) {
            int a3 = dp[p3] * 3;
            int a5 = dp[p5] * 5;
            int a7 = dp[p7] * 7;
            int t = min({a3, a5, a7});
            if (t == a3) ++p3;
            if (t == a5) ++ p5;
            if (t == a7) ++p7;
            dp.push_back(t);
        }
        return dp.back();
    }
};
