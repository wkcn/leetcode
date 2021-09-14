#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    if (graph.empty()) return 0;
    const int n = graph.size();
    vector<vector<int>> vis(n, vector<int>(1 << n));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      q.emplace(i, 1 << i);
      vis[i][1 << i] = true;
    }
    int step = 0;
    while (!q.empty()) {
      ++step;
      int size = q.size();
      while (size--) {
        auto [s, mask] = q.front(); q.pop();
        for (int t : graph[s]) {
          int new_mask = mask | (1 << t);
          if (vis[t][new_mask]) continue;
          vis[t][new_mask] = true;
          if (new_mask == (1 << n) - 1) {
            return step;
          }
          q.emplace(t, new_mask);
        }
      }
    }
    return 0;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<vector<int>> dis(n, vector<int>(n, n));
    for (int i = 0; i < n; ++i) {
      dis[i][i] = 0;
      for (int t : graph[i]) {
        dis[i][t] = 1;
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
    // dp[i][mask], 以i点结束
    vector<vector<int>> dp(n, vector<int>(1 << n, INT32_MAX));
    for (int i = 0; i < n; ++i) {
      dp[i][1 << i] = 0;
    }
    for (int mask = 1; mask < (1 << n) - 1; ++mask) {
      // mask is a start state
      for (int i = 0; i < n; ++i) {
        int new_mask = mask | (1 << i);
        if (mask != new_mask) {
          for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
              // j -> i
              dp[i][new_mask] = min(dp[i][new_mask], dp[j][mask] + dis[j][i]);
            }
          }
        }
      }
    }
    const int fmask = (1 << n) - 1;
    int ans = dp[0][fmask];
    for (int i = 1; i < n; ++i) ans = min(ans, dp[i][fmask]);
    return ans;
  }
};

#endif

int main() {
  vector<vector<int>> graph{{1,2,3},{0},{0},{0}};
  cout << Solution().shortestPathLength(graph) << endl;
  return 0;
}
