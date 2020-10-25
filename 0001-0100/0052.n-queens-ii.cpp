class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        vector<int> G(n, -1); // G[r] = c; 代表第r行放在第c列
        return go(G, 0, n);
    }
    int go(vector<int> &G, int r, int n) {
        if (r == n) return 1;
        int cnt = 0;
        for (int c = 0; c < n; ++c) {
            // 判断是否可以放
            bool can = true;
            for (int t = 0; t < r; ++t) {
                if (G[t] == -1) continue;
                if (G[t] == c || (G[t] - t == c - r) || (G[t] + t == c + r)) {
                    can = false;
                    break;
                }
            }
            if (can) {
                G[r] = c;
                cnt += go(G, r + 1, n);
            }
        }
        return cnt;
    }
};
