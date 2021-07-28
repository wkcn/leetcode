class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for (int c = 0; c < n; ++c) {
            if (obstacleGrid[0][c]) break;
            dp[c] = 1;
        }
        for (int r = 1; r < m; ++r) {
            if (obstacleGrid[r][0]) dp[0] = 0;
            for (int c = 1; c < n; ++c) {
                if (obstacleGrid[r][c]) {
                    dp[c] = 0;
                } else {
                    dp[c] = dp[c-1] + dp[c];
                }
            }
        }
        return dp.back();
    }
};
