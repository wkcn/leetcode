class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> out(m);
        for (int i = 0; i < m; ++i) {
            auto p = original.begin() + i * n;
            out[i] = vector<int>(p, p + n);
        }
        return out;
    }
};
