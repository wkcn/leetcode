#include "common.h"

#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      // dijkstra
      // 对于一个点，可能转乘最少，也可能步数最少，遇到最少时要广播
      vector<pair<int, int>> dp(n, {INT32_MAX, INT32_MAX});  // (距离，步数)
      vector<vector<pair<int, int>>> G(n);
      for (auto &v : flights) {
        G[v[0]].emplace_back(v[1], v[2]);
      }
      using A3 = array<int, 3>;  // 距离，步数，开始位置
      priority_queue<A3, vector<A3>, greater<A3>> pq;
      pq.push({0, 0, src});
      while (!pq.empty()) {
        auto a3 = move(pq.top()); pq.pop();
        int dis = a3[0], step = a3[1], start = a3[2];
        bool updated = false;
        if (dis < dp[start].first) {
          dp[start].first = dis;
          updated = true;
        }
        if (step < dp[start].second) {
          dp[start].second = step;
          updated = true;
        }
        if (updated && step <= k) {
          for (auto [to, price] : G[start]) {
            pq.push({dis + price, step + 1, to});
          }  
        }
      }
      return dp[dst].first == INT32_MAX ? -1 : dp[dst].first;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      // dp[2][t] step步内到达t点的最短距离
      vector<vector<int>> dp(2, vector<int>(n, INT32_MAX));
      vector<vector<pair<int, int>>> G(n);
      for (auto &v : flights) {
        G[v[0]].emplace_back(v[1], v[2]);
      }
      dp[0][src] = 0;
      for (int i = 0; i <= k; ++i) {
        const int cur = i & 1, next = 1 - cur;
        dp[next] = dp[cur];
        for (int s = 0; s < n; ++s) {
          if (dp[cur][s] != INT32_MAX) {
            for (auto [t, d] : G[s]) {
              dp[next][t] = min({dp[next][t], dp[cur][s] + d});
            }
          }
        }
      }
      auto D = dp[1 - (k & 1)];
      return D[dst] == INT32_MAX ? -1 : D[dst]; 
    }
};

#elif SOLUTION == 3

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      // dp[2][t] step步内到达t点的最短距离
      vector<vector<int>> dp(2, vector<int>(n, INT32_MAX));
      dp[0][src] = 0;
      int ans = dp[0][dst];
      for (int i = 0; i <= k; ++i) {
        const int cur = i & 1, next = 1 - cur;
        for (auto &v : flights) {
          if (dp[cur][v[0]] != INT32_MAX)
            dp[next][v[1]] = min({dp[next][v[1]], dp[cur][v[0]] + v[2]});
        }
        ans = min(ans, dp[next][dst]);
      }
      return ans == INT32_MAX ? -1 : ans;
    }
};

#endif

int main() {
  int n = 3;
  vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
  int src = 0, dst = 2, k = 1;
  cout << Solution().findCheapestPrice(n, edges, src, dst, k) << endl;
  cout << Solution().findCheapestPrice(n, edges, src, dst, 0) << endl;
  return 0;
}
