#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      if (n == 0) return {};
      vector<vector<int> > ans(n, vector<int>(n, 0));
      int r = 0, c = -1;
      int i = 1;
      int step;
      int cir = 0;
      while (i <= n * n) {
        step = n - cir;
        while (step-- > 0) ans[r][++c] = i++;
        step = n - cir - 1;
        while (step-- > 0) ans[++r][c] = i++;
        step = n - cir - 1;
        while (step-- > 0) ans[r][--c] = i++;
        step = n - cir - 2;
        while (step-- > 0) ans[--r][c] = i++;
        cir += 2;
      }
      return ans;
    }
};

int main() {
  int n;
  cin >> n;
  PRINT_MATRIX(Solution().generateMatrix(n));
  return 0;
}
