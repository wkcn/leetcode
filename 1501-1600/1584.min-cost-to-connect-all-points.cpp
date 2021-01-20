// Kruskal
struct Edge {
    int i, j;
    int d;
    bool operator<(const Edge &b) const {
        return d < b.d;
    }
};

class UnionFind {
public:
    UnionFind(int n) : parents(n) {
        iota(parents.begin(), parents.end(), 0);
    }
    int GetParent(int a) {
        if (parents[a] == a) return a;
        return parents[a] = GetParent(parents[a]);
    }
    void Connect(int a, int b) {
        parents[a] = b;
    }
private:
    vector<int> parents;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(points[i][0] - points[j][0]) + \
                        abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, d});
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(n);
        int ans = 0;
        for (Edge &e : edges) {
            int pa = uf.GetParent(e.i);
            int pb = uf.GetParent(e.j);
            if (pa == pb) continue;
            ans += e.d;
            uf.Connect(pa, pb);
        }
        return ans;
    }
};

struct Edge {
    int i, j;
    int d;
    bool operator>(const Edge &b) const {
        return d > b.d;
    }
};

// Prim
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        const int n = points.size();
        vector<bool> used(n, false);
        priority_queue<Edge, vector<Edge>, greater<Edge> > q;
        int cnt = 0;
        auto Push = [&](int r) {
            used[r] = true;
            ++cnt;
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                int d = abs(points[r][0] - points[i][0]) + \
                        abs(points[r][1] - points[i][1]);
                q.push({r, i, d});
            }
        };
        Push(0);
        int ans = 0;
        while (!q.empty() && cnt < n) {
            auto e = q.top(); q.pop();
            if (used[e.j]) continue;
            // 加入e.j
            ans += e.d;
            Push(e.j);
        }
        return ans;
    }
};
