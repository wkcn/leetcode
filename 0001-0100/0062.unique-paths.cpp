// TDOO: 杨辉三角
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
           1 1 1 1 1
           1 2 3 4 5
           1 3 6 10 15: 2, 3, 4, 5
           1 4 10 20 35: 3, 6, 10, 15
           f(r, c) = f(r-1, c) + f(r, c - 1)


           杨辉三角
           1
           1 1
           1 2 1
           1 3 3 1
           1 4 6 4 1: C(2, 4) = 6
         */
         if (m < n) return uniquePaths(n, m);
         vector<int> dp(n, 1);
         for (int r = 1; r < m; ++r) {
             for (int c = 1; c < n; ++c) {
                 dp[c] += dp[c-1];
             }
         }
         return dp.back();
    }
};
