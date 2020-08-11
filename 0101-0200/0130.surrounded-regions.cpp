// 可以先对外面一圈做标记
#include "common.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int rows = board.size();
        if (rows == 0) return;
        const int cols = board[0].size();
        if (cols == 0) return;
        unordered_set<int> vis;
        int cur = -1;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    queue<pair<int, int> > q;
                    q.push({r, c});
                    board[r][c] = cur;
                    bool out = false;
                    auto F = [&](unsigned int nr, unsigned int nc) {
                        if (nr >= rows || nc >= cols) {
                            out = true;
                            return;
                        }
                        if (board[nr][nc] == 'O') {
                            board[nr][nc] = cur;
                            q.push({nr, nc});
                        }
                    };
                    while (!q.empty()) {
                        auto [nr, nc] = q.front(); q.pop();
                        F(nr, nc+1);
                        F(nr, nc-1);
                        F(nr-1, nc);
                        F(nr+1, nc);
                    }
                    if (out) {
                        vis.insert(cur);
                    }
                    --cur;
                }
            }
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] < 0) {
                    if (vis.count(board[r][c])) board[r][c] = 'O';
                    else board[r][c] = 'X';
                }
            }
        }
    }
};

int main() {
  vector<vector<char> > board;
  INPUT_MATRIX(board);
  Solution().solve(board);
  PRINT_MATRIX(board);
  return 0;
}
