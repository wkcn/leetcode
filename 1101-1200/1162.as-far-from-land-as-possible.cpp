// TODO: 两阶段的DP
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        int rows = grid.size();
        int cols = grid[0].size();
        int land = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    grid[r][c] = -1;
                    ++land;
                }
            }
        }
        if (land == rows * cols || land == 0) return -1;


        int step = 0;
        int ans = 0;
        auto F = [&](unsigned int r, unsigned int c) {
            if (r >= rows || c >= cols) return;
            if (grid[r][c] == 0) {
                ans = step;
                q.push({r, c});
                grid[r][c] = -1;
            }
        };

        while (!q.empty()) {
            int size = q.size();
            ++step;
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                F(r+1, c);
                F(r-1, c);
                F(r, c+1);
                F(r, c-1);
            }
        }
        return ans;
    }
};
