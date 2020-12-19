class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先水平翻转, 然后按对角线翻转
        const int R = matrix.size();
        if (R == 0) return;
        const int C = matrix[0].size();
        if (C == 0) return;
        // 3 -> 1, 4 -> 2
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C / 2; ++c) {
                swap(matrix[r][c], matrix[r][C - c - 1]);
            }
        }
        // 对角线
        for (int r = 0; r < R - 1; ++r) {
            for (int c = 0; c < C - 1 - r; ++c) {
                swap(matrix[r][c], matrix[C - c - 1][R - r - 1]);
            }
        }
    }
};
