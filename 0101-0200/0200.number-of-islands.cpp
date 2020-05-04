// TODO: 并查集
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        int land = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++land;
                    queue<pair<int, int> > q;
                    q.push({r, c});
                    grid[r][c] = '2';
                    auto F = [&](unsigned int r, unsigned int c) {
                        if (r >= rows || c >= cols) return;
                        if (grid[r][c] == '1') {
                            grid[r][c] = '2';
                            q.push({r, c});
                        }
                    };
                    while (!q.empty()) {
                        auto [rr, cc] = q.front(); q.pop();
                        F(rr+1, cc);
                        F(rr-1, cc);
                        F(rr, cc-1);
                        F(rr, cc+1);
                    }
                }
            }
        }
        return land;
    }
};
