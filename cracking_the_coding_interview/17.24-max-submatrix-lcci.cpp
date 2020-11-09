#include "common.h"

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int> > su(rows + 1, vector<int>(cols + 1, 0));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                su[r + 1][c + 1] = matrix[r][c] + su[r][c + 1]; // 从上到下累加
            }
        }
        vector<int> res{0, 0, 0, 0};
        int best = matrix[0][0];
        for (int r1 = 0; r1 < rows; ++r1) {
            for (int r2 = r1; r2 < rows; ++r2) {
                int s = su[r2 + 1][0 + 1] - su[r1][0 + 1];
                cout << r1 << ", " << r2 << ": " << s << endl;
                if (s > best) {
                    best = s;
                    res = {r1, 0, r2, 0};
                }
                int start_c = 0;
                for (int c = 1; c < cols; ++c) {
                    int t = su[r2 + 1][c + 1] - su[r1][c + 1];
                    int u = t + s;
                    if (u >= t) {
                        s = u;
                    } else {
                        s = t;
                        start_c = c;
                    }
                    cout << "C " << c << ": " << t << " | " << s << endl;
                    if (s > best) {
                        best = s;
                        res = {r1, start_c, r2, c};
                    }
                }
            }
        }
        return res;
    }
};

int main() {
  vector<vector<int> > matrix;
  INPUT_ARRAY2D(matrix);
  PRINT_ARRAY(Solution().getMaxMatrix(matrix));
  return 0;
}
