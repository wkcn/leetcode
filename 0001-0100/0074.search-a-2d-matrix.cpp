class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        if (rows == 0) return false;
        const int cols = matrix[0].size();
        if (cols == 0) return false;
        int r = rows - 1, c = 0;
        while (r >= 0 && c < cols) {
            int v = target - matrix[r][c];
            if (v == 0) return true;
            v < 0 ? --r : ++c;
        }
        return false;
    }
};
