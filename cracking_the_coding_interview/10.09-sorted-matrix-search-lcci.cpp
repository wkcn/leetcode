class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        if (rows == 0) return false;
        const int cols = matrix[0].size();
        if (cols == 0) return false;
        int r = rows - 1, c = 0;
        while (matrix[r][c] != target) {
            if (matrix[r][c] > target) {if (--r < 0) return false;}
            else if (++c >= cols) return false;
        }
        return true;
    }
};
