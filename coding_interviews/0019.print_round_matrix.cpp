#include "common.h"

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  vector<int> printMatrix(vector<vector<int> > matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return {};
    int row = matrix.size();
    int col = matrix[0].size();
    int step = row * col;
    int r = 0, c = -1;
    int d = 0;
    int steps[4] = {col, row-1, col-1, row-2};
    vector<int> res;
    while (step > 0) {
      int w = steps[d];
      for (int i = 0; i < w; ++i) {
        r += dir[d][0];
        c += dir[d][1];
        res.push_back(matrix[r][c]);
      }
      step -= w;
      steps[d] -= 2;
      d = (d + 1) % 4;
    }
    return res;
  }
};

int main() {
  vector<vector<int> > matrix;
  INPUT_ARRAY2D(matrix);
  PRINT_ARRAY(Solution().printMatrix(matrix));
  return 0;
}
