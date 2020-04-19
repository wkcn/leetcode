// 可以进一步优化
// 1. 只考虑下和右
// 2. 用动态规划
#if SOLUTION == 1
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m == 0 || n == 0) return 0;
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        queue<pair<int, int> > q;
        q.push({0, 0});
        vis[0][0] = true;
        int ans = 0;
        auto S = [](int v) {
            int a = 0;
            while (v > 0) {
                a += v % 10;
                v /= 10;
            }
            return a;
        };
        auto go = [&](unsigned int r, unsigned int c) {
            if (r >= m || c >= n || S(r)+S(c) > k) return;
            if (vis[r][c]) return;
            vis[r][c] = true;
            q.push({r, c});
        };
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ++ans;
            go(r+1, c);
            go(r-1, c);
            go(r, c+1);
            go(r, c-1);
        }

        return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int movingCount(int m, int n, int k) {
        array<int, 100> res;
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        for (int i = 0; i < 100; ++i) {
            res[i] = i / 10 + i % 10;
        }
        queue<pair<int, int> > q;
        int cnt = 1;
        q.push({0, 0});
        vis[0][0] = true;
        int r, c;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            r = p.first + 1; c = p.second;
            if (r < m && c < n && !vis[r][c] && res[r] + res[c] <= k) {
                ++cnt;
                q.push({r, c});
                vis[r][c] = 1;
            }
            r = p.first; c = p.second + 1;
            if (r < m && c < n && !vis[r][c] && res[r] + res[c] <= k) {
                ++cnt;
                q.push({r, c});
                vis[r][c] = 1;
            }
        }
        return cnt;
    }
};
#elif SOLUTION == 3
class Solution {
public:
    int movingCount(int m, int n, int k) {
        array<int, 100> res;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        for (int i = 0; i < 100; ++i) {
            res[i] = i / 10 + i % 10;
        }
        int cnt = 0;
        vis[0][0] = 1;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r > 0 && res[r] + res[c] <= k) vis[r][c] |= vis[r-1][c];
                if (c > 0 && res[r] + res[c] <= k) vis[r][c] |= vis[r][c-1];
                cnt += vis[r][c];
            }
        }
        return cnt;
    }
};
#endif
