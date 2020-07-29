#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return 0;
        const int cols = matrix[0].size();
        if (cols == 0) return 0;
        vector<vector<int> > outdeg(rows, vector<int>(cols, 0)); // 从低指向高
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                for (auto [dr, dc] : dirs) {
                    unsigned int nr = r + dr;
                    unsigned int nc = c + dc;
                    if (nr < rows && nc < cols) {
                        if (matrix[r][c] < matrix[nr][nc]) ++outdeg[r][c];
                    }
                }
            }
        }
        queue<pair<int, int> > q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (outdeg[r][c] == 0) q.push({r, c});
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front(); q.pop();
                for (auto [dr, dc] : dirs) {
                    unsigned int nr = r + dr;
                    unsigned int nc = c + dc;
                    // 注意还有一个条件，而且这里的r, c和nr, nc和上面的不同
                    if (nr < rows && nc < cols && matrix[r][c] > matrix[nr][nc]) {
                        if (--outdeg[nr][nc] == 0) q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
}; 
#elif SOLUTION == 2
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows == 0) return 0;
        const int cols = matrix[0].size();
        if (cols == 0) return 0;
        vector<vector<int> > dp(rows, vector<int>(cols, -1));

        function<int(unsigned int, unsigned int)> F;
        F = [&](unsigned int r, unsigned int c) {
            if (dp[r][c] != -1) return dp[r][c];
            int ma = 0;
            for (auto [dr, dc] : dirs) {
                unsigned int nr = r + dr;
                unsigned int nc = c + dc;
                if (nr < rows && nc < cols) {
                    if (matrix[r][c] < matrix[nr][nc]) {
                        ma = max(ma, F(nr, nc));
                    }
                }
            }
            return (dp[r][c] = ma + 1);
        };
        int best = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                best = max(F(r, c), best);
            }
        }
        return best;
    }
};
#endif

int main() {
  vector<vector<int> > matrix;
  INPUT_ARRAY2D(matrix);
  cout << Solution().longestIncreasingPath(matrix) << endl;
  return 0;
}
