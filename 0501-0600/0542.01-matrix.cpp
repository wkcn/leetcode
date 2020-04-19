// TODO: DP
#include "common.h"

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return {};
        const int cols = matrix[0].size();
        if (cols == 0) return {};
        queue<pair<int, int> > q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    q.push({r, c});
                    matrix[r][c] |= (1<<31);
                }
            }
        }
        int step = 0;
        auto go = [&](unsigned int r, unsigned int c) {
            if (r >= rows || c >= cols) return;
            if (matrix[r][c] & (1<<31)) return;
            q.push({r, c});
            matrix[r][c] |= (1<<31);
        };
        while (!q.empty()) {
            int size = q.size(); 
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                matrix[r][c] = step | (1 << 31);
                go(r+1, c);
                go(r-1, c);
                go(r, c+1);
                go(r, c-1);
            }
            ++step;
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                matrix[r][c] &= ~(1<<31);
            }
        }
        return matrix;
    }
};

int main() {
  vector<vector<int> > mat;
  INPUT_ARRAY2D(mat);
  PRINT_MATRIX(Solution().updateMatrix(mat));
  return 0;
}
