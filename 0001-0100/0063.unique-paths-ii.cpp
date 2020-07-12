class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1]
        const int rows = obstacleGrid.size();
        if (rows == 0) return 0;
        const int cols = obstacleGrid[0].size();
        if (cols == 0) return 0;
        vector<int> dp(cols, 0);
        // 第一行
        for (int c = 0; c < cols; ++c) {
            if (obstacleGrid[0][c]) break;
            dp[c] = 1;
        }
        for (int r = 1; r < rows; ++r) {
            // c == 0
            if (obstacleGrid[r][0]) dp[0] = 0;
            for (int c = 1; c < cols; ++c) {
                if (obstacleGrid[r][c]) {
                    dp[c] = 0;
                } else {
                    dp[c] = dp[c] + dp[c-1];
                }
            }
        }
        return dp.back();
    }
};
