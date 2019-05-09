#include "common.h"

typedef unsigned long long ULL;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int row = obstacleGrid.size();
      int col = obstacleGrid[0].size();
      if (obstacleGrid[0][0] == 1) return 0;
      vector<ULL> ma(col, 0);
      for (int c = 0; c < col; ++c) {
        if (obstacleGrid[0][c]) break;
        ma[c] = 1; 
      }
      for (int r = 1; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          if (obstacleGrid[r][c]) {
            ma[c] = 0;
          } else {
            if (c > 0) {
              ma[c] += ma[c - 1];
            }
          }
        }
      }
      return ma[col - 1];
    }
};

int main() {
  vector<vector<int> > obs;
  INPUT_ARRAY2D(obs);
  cout << Solution().uniquePathsWithObstacles(obs) << endl;
  return 0;
}
