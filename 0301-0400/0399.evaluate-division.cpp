class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> s2i;
        vector<vector<pair<int, double> > > G;
        GenGraph(equations, values, s2i, G);
        vector<double> ans;
        for (auto &q : queries) {
            ans.push_back(Query(s2i, G, q));
        }
        return ans;
    }
    void GenGraph(vector<vector<string> > & equations, vector<double> &values, 
                  unordered_map<string, int> &s2i, vector<vector<pair<int, double> > > &G) {
        for (auto &u : equations) {
            s2i.insert({u[0], s2i.size()});
            s2i.insert({u[1], s2i.size()});
        }
        G.resize(s2i.size());
        int i = 0;
        for (auto &u : equations) {
            int a = s2i[u[0]];
            int b = s2i[u[1]];
            double v = values[i];
            G[a].push_back({b, v});
            G[b].push_back({a, 1.0 / v});
            ++i;
        }
    }
    double Query(unordered_map<string, int> &s2i, vector<vector<pair<int, double> > > &G, vector<string> &qe) {
        auto start_p = s2i.find(qe[0]);
        auto target_p = s2i.find(qe[1]);
        if (start_p == s2i.end() || target_p == s2i.end()) return -1;
        const int start = start_p->second;
        const int target = target_p->second;
        queue<pair<int, double> > q; q.push({start, 1.0});
        unordered_set<int> vis; vis.insert(start);
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize-- > 0) {
                pair<int, double> r = q.front(); q.pop();
                if (r.first == target) return r.second;
                for (pair<int, double> &t : G[r.first]) {
                    if (vis.insert(t.first).second) {
                        double v = r.second * t.second;
                        q.push({t.first, v});
                    }
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> s2i;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            for (string &s : p) {
                s2i.insert({s, s2i.size()});
            }
        }
        const int n = s2i.size();
        vector<vector<double> > G(n, vector<double>(n, -1));
        for (int i = 0; i < n; ++i) G[i][i] = 1.0;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            double v = values[i];
            int a = s2i[p[0]], b = s2i[p[1]];
            G[a][b] = v;
            G[b][a] = 1.0 / v;
        }
        // floyed
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (G[i][j] == -1 && G[i][k] != -1 && G[k][j] != -1) {
                        G[i][j] = G[i][k] * G[k][j];
                    }
                }
            }
        }
        vector<double> ans;
        for (auto &p : queries) {
            auto pa = s2i.find(p[0]);
            auto pb = s2i.find(p[1]);
            if (pa != s2i.end() && pb != s2i.end()) {
                ans.push_back(G[pa->second][pb->second]);
            } else ans.push_back(-1);
        }
        return ans;
    }
};

// 带权并查集, root = -1
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> s2i;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            for (string &s : p) {
                s2i.insert({s, s2i.size()});
            }
        }
        const int n = s2i.size();
        vector<pair<int, double> > G(n, {-1, 1.0}); // (pid, weight), weight 指到pid的权重
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            int a = s2i[p[0]], b = s2i[p[1]];
            // a -> b (v)
            int pa = get_parent(G, a);
            int pb = get_parent(G, b);
            // V[a] / V[pa] = G[a].second
            // V[b] / V[pb] = G[b].second
            // V[a] / V[b] = v
            // V[pa] / V[pb] = G[b].second / G[a].second * v
            if (pa != pb) {
                // 避免自环
                G[pa].first = pb;
                G[pa].second = G[b].second / G[a].second * values[i];
            }
        }
        vector<double> ans;
        for (auto &p : queries) {
            auto ia = s2i.find(p[0]);
            auto ib = s2i.find(p[1]);
            if (ia != s2i.end() && ib != s2i.end()) {
                int pa = get_parent(G, ia->second);
                int pb = get_parent(G, ib->second);
                if (pa != pb) ans.push_back(-1);
                else {
                    ans.push_back(G[ia->second].second / G[ib->second].second);
                }
            } else ans.push_back(-1);
        }
        return ans;
    }
    int get_parent(vector<pair<int, double> > &G, int a) {
        auto &p = G[a];
        if (p.first == -1) return a;  // single
        int t = get_parent(G, p.first);
        // a -> p.first -> t
        p.second *= G[p.first].second;
        p.first = t;
        return t;
    }
};

// 带权并查集, root = self_id
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> s2i;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            for (string &s : p) {
                s2i.insert({s, s2i.size()});
            }
        }
        const int n = s2i.size();
        vector<pair<int, double> > G(n, {-1, 1.0}); // (pid, weight), weight 指到pid的权重
        for (int i = 0; i < n; ++i) G[i].first = i;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> &p = equations[i];
            int a = s2i[p[0]], b = s2i[p[1]];
            // a -> b (v)
            int pa = get_parent(G, a);
            int pb = get_parent(G, b);
            // V[a] / V[pa] = G[a].second
            // V[b] / V[pb] = G[b].second
            // V[a] / V[b] = v
            // V[pa] / V[pb] = G[b].second / G[a].second * v
            {
                // parent为自己时，不用避免自环
                G[pa].first = pb;
                G[pa].second = G[b].second / G[a].second * values[i];
            }
        }
        vector<double> ans;
        for (auto &p : queries) {
            auto ia = s2i.find(p[0]);
            auto ib = s2i.find(p[1]);
            if (ia != s2i.end() && ib != s2i.end()) {
                int pa = get_parent(G, ia->second);
                int pb = get_parent(G, ib->second);
                if (pa != pb) ans.push_back(-1);
                else {
                    ans.push_back(G[ia->second].second / G[ib->second].second);
                }
            } else ans.push_back(-1);
        }
        return ans;
    }
    int get_parent(vector<pair<int, double> > &G, int a) {
        auto &p = G[a];
        if (p.first == a) return a;  // single
        int t = get_parent(G, p.first);
        // a -> p.first -> t
        p.second *= G[p.first].second;
        p.first = t;
        return t;
    }
};
