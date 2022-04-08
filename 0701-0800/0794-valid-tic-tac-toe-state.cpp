#include "common.h"

void PRINT_CHESS(int y) {
  int i = 0;
  char CC[5] = " XO-";
  cout << "===" << endl;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      int t = (y >> (i * 2)) & 0b11;
      cout << CC[t] << "\t";
      ++i;
    }
    cout << endl;
  }
}

class Solution {
public:
  bool validTicTacToe(vector<string>& board) {
    int i = 0;
    int mask = 0;
    // 2 bit * 9
    for (int r = 0; r < 3; ++r) {
      for (int c = 0; c < 3; ++c) {
        mask |= CKind(board[r][c]) << (i * 2);
        ++i;
      }
    }
    if (mask == 0) return true;
    queue<int> q;
    q.push(0);
    unordered_set<int> vis;
    vis.insert(0);
    int now = CKind('X');
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int t = q.front(); q.pop();
        int i = 0;
        for (int r = 0; r < 3; ++r) {
          for (int c = 0; c < 3; ++c, ++i) {
            if (!(t & (0b11 << (i * 2)))) {
              int y = t | (now << (i * 2));
              if (vis.count(y)) continue;
              vis.insert(y);
              if (y == mask) return true;
              if (!IsWin(y)) {
                q.push(y);
              }
            }
          }
        }
      }
      now = (~now) & 0b11;
    }
    return false;
  }
  int CKind(char c) {
    switch (c) {
      case 'X':
        return 0b01;
      case 'O':
        return 0b10;
    }
    return 0b00;
  }
  bool IsWin(int s) {
    if (((s >> 12) & (s >> 6) & s) & 0b111111) return true;
    if (((s >> 4) & (s >> 2) & s) & 0b000011000011000011) return true;
    if (((s >> 16) & (s >> 8) & s) & 0b11) return true;
    if (((s >> 12) & (s >> 8) & (s >> 4)) & 0b11) return true;
    return false;
  }
};

int main() {
  {
  vector<string> board{"   "," X ","   "};
  cout << Solution().validTicTacToe(board) << endl;
  }
  {
  vector<string> board{"XOX"," X ","   "};
  cout << Solution().validTicTacToe(board) << endl;
  }
  {
  vector<string> board{"XOX","O O","XOX"};
  cout << Solution().validTicTacToe(board) << endl;
  }
  {
  vector<string> board{"XXX","OOX","OOX"};
  cout << Solution().validTicTacToe(board) << endl;
  }
  return 0;
}
