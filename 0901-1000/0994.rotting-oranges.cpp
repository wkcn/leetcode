// 多源广度优先搜索
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows == 0) return 0;
        const int cols = grid[0].size();
        if (cols == 0) return 0;
        int fruit = 0;
        for (vector<int> &vs : grid) {
            for (int v: vs) {
                if (v == 1) ++ fruit;
            }
        }
        if (fruit == 0) return 0; // 注意特殊值
        int minute = 0;
        while (1) {
            // update
            int new_fruit = 0;
            vector<pair<int, int> > bad;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    int &v = grid[r][c];
                    if (v == 1) {
                        bool valid = true;
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dir[d][0];
                            int nc = c + dir[d][1];
                            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 2) {
                                bad.push_back({r, c});
                                valid = false;
                                break;
                            }
                        }
                        if (valid) ++new_fruit;
                    }
                }
            }
            if (new_fruit == fruit) {
                return -1;
            }
            ++minute;
            if (new_fruit == 0) return minute;
            fruit = new_fruit;
            for (auto &p : bad) {
                grid[p.first][p.second] = 2;
            }
        }
        return 0;
    }
};
#elif SOLUTION == 2

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int rows = grid.size();
    if (rows == 0) return 0;
    const int cols = grid[0].size();
    if (cols == 0) return 0;
    int fruit = 0;
    queue<pair<int, int> > q;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        switch (grid[r][c]) {
          case 1:
            ++fruit;
            break;
          case 2:
            q.push({r, c});
            break;
        }
      }
    }
    if (fruit == 0) return 0; // 注意特殊值
    int minute = 0;
    while (!q.empty()) {
      int size = q.size();
      ++minute;
      while (size--) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
          unsigned int nr = r + dir[d][0];
          unsigned int nc = c + dir[d][1];
          if (nr < rows && nc < cols && grid[nr][nc] == 1) {
            grid[nr][nc] = 2;
            if (--fruit == 0) {
              return minute;
            }
            q.push({nr, nc});
          }
        }
      }
    }
    return -1;
  }
};


#endif

int main() {
  vector<vector<int> > grid;
  INPUT_ARRAY2D(grid);
  cout << Solution().orangesRotting(grid) << endl;
  return 0;
}
