class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        int ans = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    ans += 4;
                    for (auto [dr, dc] : vector<pair<int, int>>{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}) {
                        unsigned int nr = r + dr;
                        unsigned int nc = c + dc;
                        if (nr < rows && nc < cols) {
                            if (grid[nr][nc] == 1) --ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
