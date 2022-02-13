#include "common.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        auto go = [&](int r, int c) {
            using P = pair<int, int>;
            queue<P> q; q.emplace(r, c);
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int i = 0; i < 4; ++i) {
                    unsigned int nr = r + DIRS[i][0];
                    unsigned int nc = c + DIRS[i][1];
                    if (nr < R && nc < C && !vis[nr][nc] && grid[nr][nc] == 1) {
                        q.emplace(nr, nc);
                        vis[nr][nc] = true;
                    }
                }
            }
        };
        for (int c = 0; c < C; ++c) {
            go(-1, c);
            go(R, c);
        }
        for (int r = 0; r < R; ++r) {
            go(r, -1);
            go(r, C);
        }
        int ans = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (!vis[r][c] && grid[r][c] == 1) ++ans;
            }
        }
        return ans;
    }
private:
    const int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main() {
  vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  cout << Solution().numEnclaves(grid) << endl;
  return 0;
}
