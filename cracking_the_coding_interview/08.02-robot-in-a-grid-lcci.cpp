class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int row = obstacleGrid.size();
        if (row == 0) return {};
        const int col = obstacleGrid[0].size();
        if (col == 0) return {};
        if (obstacleGrid[0][0] || obstacleGrid.back().back()) return {};
        const int ma = row + col;
        vector<vector<int> > dp(row, vector<int>(col, ma));
        for (int c = 0; c < col; ++c) {
            if (!obstacleGrid[0][c]) dp[0][c] = c;
            else break; // 注意这里的break
        }
        for (int r = 1; r < row; ++r) {
            // (r, 0)
            dp[r][0] = obstacleGrid[r][0] ? ma : dp[r-1][0] + 1;
            for (int c = 1; c < col; ++c) {
                if (!obstacleGrid[r][c]) {
                    dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + 1;
                } else {
                    dp[r][c] = ma;
                }
            }
        }
        if (dp.back().back() >= ma) return {};
        // back
        vector<vector<int> > ans;
        int r = row - 1, c = col - 1;
        for (int s = r+c-1; s >= 0; --s) {
            ans.push_back({r, c});
            if (r-1>=0 && dp[r-1][c] == s) --r;
            else --c;
        }
        ans.push_back({0, 0}); // 数清楚有几个坐标
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
