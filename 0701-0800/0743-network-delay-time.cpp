class Solution {
  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      if (n <= 1) return 0;
      unordered_map<int, vector<pair<int, int>>> ma;
      for (auto &vs : times) {
        ma[vs[0]].emplace_back(vs[1], vs[2]);
      }
      priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q; q.push({0, k});
      vector<bool> vis(n, false);
      int rest = n;
      while (!q.empty()) {
        auto [d, r] = q.top(); q.pop();
        if (vis[r]) continue;
        vis[r] = true;
        if (--rest == 0) return d;
        for (auto [v, w] : ma[r]) {
          if (!vis[v]) q.push({d + w, v});
        }
      }
      return -1;
    }
};
