#include "common.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      short valid[3][9];
      memset(valid, 0, sizeof(valid));
      for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
          char &vchar = board[r][c];
          if (vchar == '.') continue;
          int v = vchar - '0'; 
          int u = 1 << v;
          int g = (r / 3) * 3 + c / 3;
          if ((valid[0][r] & u) || (valid[1][c] & u) || (valid[2][g] & u)) return false;
          valid[0][r] |= u;
          valid[1][c] |= u;
          valid[2][g] |= u;
        }
      }
      return true;
    }
};

int main() {
  vector<vector<char> > board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  cout << Solution().isValidSudoku(board) << endl;
  return 0;
}
