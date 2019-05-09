#include "common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      vector<int> su(col);
      su[0] = grid[0][0];
      for (int c = 1; c < col; ++c) {
        su[c] = su[c-1] + grid[0][c];
      }
      for (int r = 1; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          if (c > 0) {
            su[c] = min(su[c-1], su[c]) + grid[r][c];
          } else {
            // c == 0
            su[c] += grid[r][c];
          }
        }
      }
      return su[col-1];
    }
};

int main() {
  vector<vector<int>> grid;
  INPUT_ARRAY2D(grid);
  cout << Solution().minPathSum(grid) << endl;
  return 0;
}
