class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int row = grid.size();
        if (row == 0) return 0;
        const int col = grid[0].size();
        if (col == 0) return 0;
        vector<int> dp(col);
        dp[0] = grid[0][0];
        for (int c = 1; c < col; ++c) {
            dp[c] = dp[c-1] + grid[0][c];
        }
        for (int r = 1; r < row; ++r) {
            dp[0] += grid[r][0];
            for (int c = 1; c < col; ++c) {
                dp[c] = min(dp[c-1], dp[c]) + grid[r][c];
            }
        }
        return dp.back();
    }
};
