// 需要分清出入度, 拓扑排序
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 终点的出度为0, 且节点到终点的路径没有节点在环上
        const int n = graph.size();
        vector<vector<int> > ig(n);
        vector<int> out_degree(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int t : graph[i]) {
                ig[t].push_back(i);
            }
        }
        queue<int> q;
        vector<int> out;
        for (int i = 0; i < n; ++i) {
            out_degree[i] = graph[i].size();
            if (out_degree[i] == 0) {
                q.push(i);
                out.push_back(i);
            }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int t : ig[v]) {
                if (--out_degree[t] == 0) {
                    q.push(t);
                    out.push_back(t);
                }
            }
        }
        sort(out.begin(), out.end());
        return out;
    }
};

// DFS染色
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 终点的出度为0, 且节点到终点的路径没有节点在环上
        const int n = graph.size();
        vector<int> out;
        vector<int> colors(n, 0); // 3种状态: 0: 未访问, 1: 正在访问, 2: 访问结束
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, colors)) {
                out.push_back(i);
            }
        }
        return out;
    }
    bool dfs(int i, const vector<vector<int> > &graph, vector<int> &colors) {
        if (colors[i] > 0) return colors[i] == 2;
        colors[i] = 1;
        for (int t : graph[i]) {
            if (!dfs(t, graph, colors)) {
                return false;
            }
        }
        colors[i] = 2;
        return true;
    }
};
