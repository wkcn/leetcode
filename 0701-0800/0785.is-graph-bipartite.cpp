class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int len = graph.size();
        if (len == 0) return true;
        vector<int> colors(len, -1);
        for (int i = 0; i < len; ++i) {
            if (colors[i] == -1) {
                queue<pair<int, bool> > q;
                q.push({i, 0});
                colors[i] = 0;
                while (!q.empty()) {
                    auto [id, c] = q.front(); q.pop();
                    bool nc = !c;
                    for (int t : graph[id]) {
                        if (colors[t] == -1) {
                            colors[t] = nc;
                            q.push({t, nc});
                        } else if (colors[t] != nc) return false;
                    }
                }
            }
        }
        return true;
    }
};
