#include "common.h"

class Solution {
  public:
    double knightProbability(int n, int k, int row, int column) {
    vector<vector<vector<double>>> ma(2, vector<vector<double>>(n, vector<double>(n)));
    ma[0][row][column] = 1;
    for (int i = 0; i < k; ++i) {
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
          double su = 0;
          for (int d = 0; d < 8; ++d) {
            unsigned int nr = r + DIRS[d][0];
            unsigned int nc = c + DIRS[d][1];
            if (nr < n && nc < n)
              su += ma[i & 1][nr][nc] / 8;
          }
          ma[(i & 1) ^ 1][r][c] = su;
        }
      }
    }

    double su = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        su += ma[k & 1][r][c];
      }
    }
    return su;
}
  private:
  const int DIRS[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
};

int main() {
  int n = 3, k = 2, row = 0, column = 0;
  cout << Solution().knightProbability(n, k, row, column) << endl;
  return 0;
}
