#include "common.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 行, 列, 九小格
        array<bitset<9>, 9> rows, cols, grid;
        auto SetVal = [&](int r, int c, int v, bool b) {
            rows[r].set(v - 1, b);
            cols[c].set(v - 1, b);
            grid[GridID(r, c)].set(v - 1, b);
        };
        auto IsValid = [&](int r, int c, int v) {
            return !rows[r][v - 1] &&
                   !cols[c][v - 1] &&
                   !grid[GridID(r, c)][v - 1];
        };
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int v = board[r][c] - '0';
                    SetVal(r, c, v, true);
                }
            }
        }
        function<bool(int, int)> DFS = [&](int r, int c) {
          cout << r << "," << c << endl;
            if (r == 9) return true;
            int nr = r;
            int nc = c + 1;
            if (nc >= 9) {
                nc = 0;
                ++nr;
            }
            if (board[r][c] == '.') {
                for (int v = 1; v <= 9; ++v) {
                  cout << "TRY: " << v << endl;
                    if (IsValid(r, c, v)) {
                        SetVal(r, c, v, true);
                        board[r][c] = v + '0';
                        if (DFS(nr, nc)) {
                            return true;
                        }
                        board[r][c] = '.';
                        SetVal(r, c, v, false);
                    }
                }
                return false;
            }
            return DFS(nr, nc);
        };
        DFS(0, 0);
    }
    int GridID(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }
};

int main() {
  vector<vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  Solution().solveSudoku(board);
  PRINT_MATRIX(board);
  return 0;
}
