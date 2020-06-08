const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return {};
        const int cols = matrix[0].size();
        if (cols == 0) return {};
        int r = 0, c = -1;
        array<int, 4> rem = {cols, rows-1, cols-1, rows-2};

        vector<int> ans;
        int d = 0;
        int steps = rows * cols;
        
        while (steps > 0) {
            for (int i = 0; i < rem[d]; ++i) {
                r += dirs[d][0];
                c += dirs[d][1];
                ans.push_back(matrix[r][c]);
                --steps;
            }
            rem[d] -= 2;
            d = (d + 1) % 4;
        }
        
        return ans;
    }
};
