const int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        stack<pair<int, int> > st;
        int best = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    int cnt = 0;
                    st.push({r, c});
                    grid[r][c] = 2;
                    while (!st.empty()) {
                        auto pos = st.top(); st.pop();
                        ++cnt;
                        for (auto& offset : offsets) {
                            unsigned int nr = pos.first + offset[0];
                            unsigned int nc = pos.second + offset[1];
                            if (nr < rows && nc < cols && grid[nr][nc] == 1) {
                                st.push({nr, nc});
                                grid[nr][nc] = 2;
                            }
                        }
                    }
                    if (cnt > best) best = cnt;
                }
            }
        }
        return best;
    }
};
