class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        const int R = grid.size();
        if (R == 0) return 0;
        const int C = grid[0].size();
        if (C == 0) return 0;
        for (int c = 1; c < C; ++c) grid[0][c] += grid[0][c - 1];
        for (int r = 1; r < R; ++r) {
            grid[r][0] += grid[r-1][0];
            for (int c = 1; c < C; ++c) {
                grid[r][c] += max(grid[r-1][c], grid[r][c-1]);
            }
        }
        return *max_element(grid[R-1].begin(), grid[R-1].end());
    }
};

class Solution {
public:
    int maxValue(const vector<vector<int>>& grid) {
        const int R = grid.size();
        if (R == 0) return 0;
        const int C = grid[0].size();
        if (C == 0) return 0;
        vector<int> dp(C);
        dp[0] = grid[0][0];
        for (int c = 1; c < C; ++c) dp[c] = dp[c - 1] + grid[0][c];
        for (int r = 1; r < R; ++r) {
            dp[0] += grid[r][0];
            for (int c = 1; c < C; ++c) {
                dp[c] = grid[r][c] + max(dp[c-1], dp[c]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
