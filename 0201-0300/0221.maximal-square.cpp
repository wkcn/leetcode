// 输入的是字符串矩阵
// 返回的是面积
// 注意边界条件的处理
// TODO: 状态压缩
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return 0;
        const int cols = matrix[0].size();
        if (cols == 0) return 0;
        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        int len = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    if (r == 0 || c == 0) {
                        dp[r][c] = 1;
                    } else {
                        dp[r][c] = min({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]}) + 1;
                    }
                    len = max(dp[r][c], len);
                } else {
                    dp[r][c] = 0;
                }
            }
        }
        return len * len;
    }
};
