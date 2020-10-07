#include "common.h"

// 本质是去掉环路, 以及导致节点度数为2的边

#define SOLUTION 1
#if SOLUTION == 1
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        vector<int> in_deg(N + 1, 0);
        for (auto &e : edges) {
            // e[0] -> e[1]
            ++in_deg[e[1]];
        }
        for (int t = N - 1; t >= 0; --t) {
          auto &e = edges[t];
          // e[0] -> e[1]
          if (in_deg[e[1]] == 2) {
            if (no_circle(edges, t)) {
              return e;
            }
          }
        }
        for (int t = N - 1; t >= 0; --t) {
          auto &e = edges[t];
          // e[0] -> e[1]
          if (in_deg[e[1]] == 1) {
            if (no_circle(edges, t)) {
              return e;
            }
          }
        }
        return {};
    }
    int find_parent(int i, vector<int> &rec) {
        int t = i;
        while (t != rec[t]) {
            t = rec[t];
        }
        while (i != t) {
            int next_i = rec[i];
            rec[i] = t;
            i = next_i;
        }
        return t;
    }
    bool no_circle(vector<vector<int> > &edges, int remove_edge) {
      const int N = edges.size();
      vector<int> rec(N + 1);
      iota(rec.begin(), rec.end(), 0);
      for (int t = 0; t < N; ++t) {
        if (t == remove_edge) continue;
        auto &e = edges[t];
        int lp = find_parent(e[0], rec);
        int rp = find_parent(e[1], rec);
        if (lp == rp) return false;
        rec[rp] = lp;
      }
      return true;
    } 
};
#elif SOLUTION == 2

// 理解一下官方的题解, 记录冲突边和导致环的边

#endif

int main() {
  int n; cin >> n;
  vector<vector<int> > edges;
  while (n--) {
    int a, b; cin >> a >> b;
    edges.push_back({a, b});
  }
  PRINT_ARRAY(Solution().findRedundantDirectedConnection(edges));
  return 0;
}
