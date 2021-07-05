#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
// 以车为节点
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
      if (source == target) return 0;
      const int n = routes.size();
      unordered_map<int, vector<int>> ma;  // pos -> car id
      unordered_set<int> tse; // car ids which can go to target
      for (int i = 0; i < n; ++i) {
        for (int y : routes[i]) {
          ma[y].push_back(i);
          if (y == target) tse.insert(i);
        }
      }
      vector<set<int>> G(n);
      for (int i = 0; i < n; ++i) {
        for (int y : routes[i]) {
          for (int t : ma[y]) {
            G[i].insert(t);
          }
        }
      }
      queue<int> q; unordered_set<int> vis;
      for (int y : ma[source]) {
        q.push(y);
        vis.insert(y);
        if (tse.count(y)) return 1;
      }
      int step = 1;
      while (!q.empty()) {
        ++step;
        int m = q.size();
        while (m-- > 0) {
          int t = q.front(); q.pop();
          for (int y : G[t]) {
            if (vis.count(y)) continue;
            if (tse.count(y)) return step;
            q.push(y);
            vis.insert(y);
          }
        }
      }
      return -1;
    }
};
#elif SOLUTION == 2

// 以地点为节点会超时
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
      if (source == target) return 0;
      const int n = routes.size();
      unordered_map<int, vector<int>> ma;
      for (int i = 0; i < routes.size(); ++i) {
        for (int y : routes[i]) {
          // 地点y
          ma[y].push_back(i);
        }
      }
      // 不能直接建图, 因为会超时
      queue<int> q; unordered_set<int> vis;
      q.push(source); vis.insert(source);
      unordered_set<int> routes_used;
      int step = 0;
      while (!q.empty()) {
        ++step;
        int m = q.size();
        while (m-- > 0) {
          // 地点x
          int x = q.front(); q.pop();
          // 从地点x出发, 可以换乘到哪些没去过的地点呢?
          // 而且这条路径, 我们从来没走过
          for (int i : ma[x]) {
            // 看看这条路径有没有走过
            if (!routes_used.count(i)) {
              routes_used.insert(i);
              for (int t : routes[i]) {
                if (t == target) return step;
                q.push(t);
                vis.insert(t);
              } 
            }
          }
        }
      }
      return -1;
    }
};

#endif

int main() {
  {
    vector<vector<int>> routes{{1,2,7}, {3,6,7}};
    cout << Solution().numBusesToDestination(routes, 1, 6) << endl;
  }
  {
    vector<vector<int>> routes{{2}, {2, 8}};
    cout << Solution().numBusesToDestination(routes, 8, 2) << endl;
  }
  return 0;
}
