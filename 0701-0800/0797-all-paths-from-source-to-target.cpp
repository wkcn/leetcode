#include "common.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      const int n = graph.size();
      vector<bool> vis(n, false);
      vector<int> path;
      vector<vector<int>> ans;
      function<void(int)> go = [&](int i) {
        if (path.back() == n - 1) {
          ans.push_back(path);
          return;
        }
        for (int t : graph[i]) {
          if (!vis[t]) {
            vis[t] = true;
            path.push_back(t);
            go(t);
            path.pop_back();
            vis[t] = false;
          }
        }
      };
      vis[0] = true;
      path.push_back(0);
      go(0);
      return ans;
    }
};

int main() {
  vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
  auto ans = (Solution().allPathsSourceTarget(graph));
  cout << "#:" << ans.size() << endl;
  for (auto &v : ans) {
    PRINT_ARRAY(v);
  }
  return 0;
}
