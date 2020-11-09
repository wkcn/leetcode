#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        // dp[r][c][0/1] 表示向左(0)或者向上(1)连续黑色数量, 包括自己
        const int rows = matrix.size();
        if (rows == 0) return {};
        const int cols = matrix[0].size();
        if (cols == 0) return {};
        vector<vector<array<int, 2> > > dp(rows, vector<array<int, 2> >(cols));
        int best_len = 0;
        int best_r, best_c;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    // 黑色
                    dp[r][c][0] = (c > 0 ? dp[r][c-1][0] : 0) + 1;
                    dp[r][c][1] = (r > 0 ? dp[r-1][c][1] : 0) + 1;
                    int len = min(dp[r][c][0], dp[r][c][1]);
                    while (len > best_len) {
                        if (dp[r][c - len + 1][1] >= len && dp[r - len + 1][c][0] >= len) {
                            best_len = len;
                            best_r = r - len + 1;
                            best_c = c - len + 1;
                            break;
                        }
                        --len;
                    }
                } else {
                    // 白色
                    dp[r][c][0] = 0;
                    dp[r][c][1] = 0;
                }
            }
        }
        if (best_len == 0) return {};
        return {best_r, best_c, best_len};
    }
};
#elif SOLUTION == 2

#endif
