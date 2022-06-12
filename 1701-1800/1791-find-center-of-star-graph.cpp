class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 中心点入度等于边数
        const int n = edges.size() + 1;
        vector<int> d(n + 1);
        for (auto &e : edges) {
            ++d[e[0]]; ++d[e[1]];
        }
        for (int i = 1; i <= n; ++i)
            if (d[i] == n - 1) return i;
        return -1;
    }
};
