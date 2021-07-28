class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();   
        vector<int> dp[2]; dp[1].resize(cols);
        dp[0] = matrix[0];
        for (int r = 1; r < matrix.size(); ++r) {
            auto &cur = dp[1 - (r&1)];
            auto &next = dp[r&1];
            for (int c = 0; c < cols; ++c) {
                next[c] = cur[c];
                if (c > 0) next[c] = min(next[c], cur[c - 1]);
                if (c < cols - 1) next[c] = min(next[c], cur[c + 1]);
                next[c] += matrix[r][c];
            }
        }
        auto &cur = dp[1 - (rows&1)];
        return *min_element(cur.begin(), cur.end());
    }
};
