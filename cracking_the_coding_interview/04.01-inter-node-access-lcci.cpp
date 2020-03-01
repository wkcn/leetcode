// 节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<bool> vis(n, false);
        vector<vector<int> > G(n);
        for (vector<int> &v : graph) {
            G[v[0]].push_back(v[1]);
        }
        queue<int> q;
        q.push(start); vis[start] = true;
        while (!q.empty()) {
            int r = q.front(); q.pop();
            if (r == target) return true;
            for (int &t : G[r]) {
                if (!vis[t]) {
                    q.push(t);
                    vis[t] = false;
                }
            }
        }
        return false;
    }
};
