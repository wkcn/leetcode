class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return;
        const int cols = matrix[0].size();
        if (cols == 0) return;
        su.resize(rows + 1, vector<int>(cols + 1));
        fill(su[0].begin(), su[0].end(), 0);
        for (int k = 1; k < rows; ++k) su[k][0] = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // 注意这里的计算
                su[r + 1][c + 1] = matrix[r][c] + su[r + 1][c] + su[r][c + 1] - su[r][c];
            }
        }
        // su[r][c] = sum(matrix[:r][:c])
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return su[row2+1][col2+1] + su[row1][col1] - su[row1][col2 + 1] - su[row2 + 1][col1];
    }
private:
    vector<vector<int> > su;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
