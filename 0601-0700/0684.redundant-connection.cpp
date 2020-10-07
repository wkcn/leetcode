// 从边开始枚举, DFS
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int> > G;
        for (auto v : edges) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        const int N = G.size();
        const int E = edges.size();
        for (int w = edges.size() - 1; w >= 0; --w) {
            auto e = edges[w];
            int u = e[0], v = e[1];
            // u to v
            vector<bool> vis(N + 1, false);
            queue<int> q;
            q.push(u);
            vis[u] = true;
            while (!q.empty()) {
                int r = q.front(); q.pop();
                if (r == v) break;
                for (int t : G[r]) {
                    if (r == u && t == v) continue;
                    if (r == v && t == u) continue;
                    if (vis[t]) continue;
                    vis[t] = true;
                    q.push(t);
                }
            }
            if (vis[v]) {
                return e;
            }
        }
        return {};
    }
};

// 并查集合
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 一开始所有节点独立
        // 假如当前的边上的两个节点的父节点相同, 则这条边是要找的边
        const int N = edges.size();
        vector<int> record(N + 1, -1);
        for (auto e : edges) {
            int u_parent = find_parent(e[0], record);
            int v_parent = find_parent(e[1], record);
            if (u_parent == v_parent) return e;
            record[u_parent] = v_parent;
        }
        return {};
    }
    int find_parent(int v, vector<int> &record) {
        if (record[v] == -1) return v;
        return (record[v] = find_parent(record[v], record));
    }
};

// 拓扑排序
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 拓扑排序, 检测环
        const int N = edges.size();
        unordered_map<int, vector<int> > G;
        vector<int> deg(N + 1, 0);
        for (auto &e : edges) {
            ++deg[e[0]];
            ++deg[e[1]];
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int t : G[r]) {
                if (--deg[t] == 1) {
                    q.push(t);
                }
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            auto &e = edges[i];
            if (deg[e[0]] >= 2 && deg[e[1]] >= 2) {
                return e;
            }
        }
        return {};
    }
};
