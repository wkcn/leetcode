class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int movingCount(int m, int n, int k) {
        set<tuple<int,int>> vis;
        function<void(int,int)> F = [&] (int r, int c) {
            vis.insert({r, c});
            for (int d = 0; d < 4; ++d) {
                unsigned int nr = r + dirs[d][0];
                unsigned int nc = c + dirs[d][1];
                if (nr < m && nc < n) {
                    if (db(nr) + db(nc) <= k) {
                        if (vis.insert({nr, nc}).second) {
                            F(nr, nc);
                        }
                    }
                }
            }
        };
        F(0, 0);
        return vis.size();
    }
    int db(int v) {
        int e = 0;
        while (v > 0) {
            e += v % 10; v /= 10;
        }
        return e;
    }
};

class Solution {
    int dirs[2][2] = {{1, 0}, {0, 1}};
public:
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        int ans = 0;
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ++ans;
            for (int d = 0; d < 2; ++d) {
                unsigned int nr = r + dirs[d][0];
                unsigned int nc = c + dirs[d][1];
                if (nr < m && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    if (db(nr) + db(nc) <= k) {
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
    int db(int v) {
        int e = 0;
        while (v > 0) {
            e += v % 10; v /= 10;
        }
        return e;
    }
};

class Solution {
    int dirs[2][2] = {{1, 0}, {0, 1}};
public:
    int movingCount(int m, int n, int k) {
        vector<bool> vis(n, false);
        vis[0] = true;
        int ans = 1;

        // r = 0
        for (int c = 1; c < n; ++c) {
            if (!vis[c - 1]) break;
            if (db(c) <= k) {
                vis[c] = true;
                ++ans;
            }
        }
        
        for (int r = 1; r < m; ++r) {
            // c = 0
            if (vis[0] && db(r) <= k) {
                ++ans;
            } else vis[0] = false;
            for (int c = 1; c < n; ++c) {
                if ((vis[c - 1] || vis[c]) && (db(r) + db(c) <= k)) {
                    vis[c] = true;
                    ++ans;
                } else vis[c] = false;
            }
        }
        return ans;
    }
    int db(int v) {
        int e = 0;
        while (v > 0) {
            e += v % 10; v /= 10;
        }
        return e;
    }
};
