#include "common.h"

// 注意这一条：如果活细胞周围八个位置有"两个"或三个活细胞，则该位置"活细胞仍然存活"；
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int rows = board.size();
        if (rows == 0) return;
        const int cols = board[0].size();
        if (cols == 0) return;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int cnt = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    unsigned int nr = r + dr;
                    if (nr >= rows) continue;
                    for (int dc = -1; dc <= 1; ++dc) {
                        unsigned int nc = c + dc;
                        if (nc >= cols) continue;
                        cnt += (board[nr][nc] >= 1);
                    }
                }
                board[r][c] = board[r][c] >= 1 ? cnt : -cnt;
            }
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int v = board[r][c];
                if (v >= 1) --v;
                else v = -v;
                if (v < 2 || v > 3 || (v == 2 && board[r][c] < 0)) board[r][c] = 0;
                else board[r][c] = 1;
            }
        }
    }
};

int main() {
  vector<vector<int> > board;
  INPUT_ARRAY2D(board);
  Solution().gameOfLife(board);
  PRINT_MATRIX(board);
  return 0;
}
