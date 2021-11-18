class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int R = matrix.size(), C = matrix[0].size();
        int r = R - 1, c = 0;
        while (r >= 0 && c < C) {
            if (matrix[r][c] == target) return true;
            matrix[r][c] < target ? ++c : --r;
        }
        return false;
    }
};
