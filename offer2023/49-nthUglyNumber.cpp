// 注意去重
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp{1};
        int a = 0, b = 0, c = 0;
        int av = 2, bv = 3, cv = 5;
        while (dp.size() < n) {
            if (av <= bv && av <= cv) {
                if (av != dp.back())
                    dp.push_back(av);
                av = dp[++a] * 2;
            } else if (bv <= av && bv <= cv) {
                if (bv != dp.back())
                    dp.push_back(bv);
                bv = dp[++b] * 3;
            } else {
                if (cv != dp.back())
                    dp.push_back(cv);
                cv = dp[++c] * 5;
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n); dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            int av = dp[a] * 2, bv = dp[b] * 3, cv = dp[c] * 5;
            dp[i] = min({av, bv, cv});
            if (dp[i] == av) ++a;
            if (dp[i] == bv) ++b;
            if (dp[i] == cv) ++c;
        }
        return dp.back();
    }
};
