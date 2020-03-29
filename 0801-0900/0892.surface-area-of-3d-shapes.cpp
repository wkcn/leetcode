// 也可以计算贴面面积
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        int ans = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int v = grid[r][c];
                if (v > 0) {
                    ans += 2;
                    ans += (r - 1 >= 0) ? max(0, v-grid[r-1][c]) : v;
                    ans += (c - 1 >= 0) ? max(0, v-grid[r][c-1]) : v;
                    ans += (r + 1 < rows) ? max(0, v-grid[r+1][c]) : v;
                    ans += (c + 1 < cols) ? max(0, v-grid[r][c+1]) : v;
                }
            }
        }
        return ans;
    }
};
