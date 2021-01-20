// 好题，逆向利用并查集，并查集
#include "common.h"

class UnionFind {
public:
  UnionFind(int size) {
    parents.resize(size);
    iota(parents.begin(), parents.end(), 0);
    cnts.resize(size, 1);
  }
  void Connect(int a, int b) {
    int pa = GetParent(a);
    int pb = GetParent(b);
    if (pa != pb) {
      parents[pa] = pb;
      cnts[pb] += cnts[pa];
    }
  }
  int GetCnt(int p) {
    return cnts[GetParent(p)];
  }
private:
  int GetParent(int p) {
    if (parents[p] == p) return p;
    return parents[p] = GetParent(parents[p]);
  }
private:
  vector<int> parents;
  vector<int> cnts;
};

const int DIRS[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // 因为并查集是补成一个连通域，而问题是拆分连通域，我们可以把打砖块的过程逆过来
        for (auto &v : hits) {
          grid[v[0]][v[1]] = -grid[v[0]][v[1]];
        }
        const int m = grid.size(), n = grid[0].size();
        const int size = m * n;

        auto GetIndex = [&](int r, int c) {
          return r * n + c;
        };

        // 连接屋顶
        UnionFind uf(size + 1); // 下标size作为屋顶
        for (int c = 0; c < n; ++c) {
          if (grid[0][c] == 1) uf.Connect(c, size);
        }
        for (int r = 1; r < m; ++r) {
          for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 1) {
              if (grid[r - 1][c] == 1) {
                uf.Connect(GetIndex(r - 1, c), GetIndex(r, c));
              }
              if (c > 0 && grid[r][c - 1] == 1) {
                uf.Connect(GetIndex(r, c - 1), GetIndex(r, c));
              }
            }
          }
        }
        // 逆序恢复
        vector<int> ans(hits.size());
        for (int i = (int)hits.size() - 1; i >= 0; --i) {
          int old_cnt = uf.GetCnt(size); 
          auto &v = hits[i];
          if (grid[v[0]][v[1]] == -1) {
            grid[v[0]][v[1]] = 1;
            // NOTICE: 如果击落的在天花板
            if (v[0] == 0) {
              uf.Connect(v[1], size);
            }
            for (auto [dr, dc] : DIRS) {
              unsigned int nr = v[0] + dr;
              unsigned int nc = v[1] + dc;
              if (nr < m && nc < n && grid[nr][nc] == 1) {
                uf.Connect(GetIndex(nr, nc), GetIndex(v[0], v[1]));
              }
            }
          }
          int new_cnt = uf.GetCnt(size); 
          // 有可能new_cnt == old_cnt
          ans[i] = max(0, new_cnt - old_cnt - 1);
        }
        return ans;
    }
};

int main() {
  {
    vector<vector<int> > grid = {{1,0,0,0},{1,1,1,0}}, hits = {{1,0}};
    PRINT_ARRAY(Solution().hitBricks(grid, hits));
  }
  {
    vector<vector<int> > grid = {{1},{1},{1},{1},{1}}, hits = {{3,0},{4,0},{1,0},{2,0},{0,0}};
    PRINT_ARRAY(Solution().hitBricks(grid, hits));
  }
  return 0;
}
