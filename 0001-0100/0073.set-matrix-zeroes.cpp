class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int R = matrix.size();
        if (R == 0) return;
        const int C = matrix[0].size();
        if (C == 0) return;
        // 如果每行左边有0标注, 说明这行需要被删掉
        // 如果第一行的第c列为0, 说明第c列要被删掉
        bool del_first_row = false;
        for (int c = 0; c < C; ++c) {
            if (matrix[0][c] == 0) {
                del_first_row = true;
                break;
            }
        }
        for (int r = 1; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < R; ++r) {
            // 需要逆序, 因为第一列可能被置零
            for (int c = C - 1; c >= 0; --c) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0)
                    matrix[r][c] = 0;
            }
        }
        if (del_first_row) {
            for (int c = 0; c < C; ++c) matrix[0][c] = 0;
        }
    }
};
