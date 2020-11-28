#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, -1));
        int r = 0, c = 0;
        int d = 0;
        const int m = n * n;
        for (int i = 1; i <= m; ++i) {
            ans[r][c] = i;
            while (i < m) {
                unsigned int nr = r + dirs[d][0];
                unsigned int nc = c + dirs[d][1];
                if (nr < n && nc < n) {
                    if (ans[nr][nc] == -1) {
                        r = nr; c = nc;
                        break;
                    }
                }
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
private:
const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

int main() {
  int n; cin >> n;
  PRINT_ARRAY2D(Solution().generateMatrix(n));
  return 0;
}
