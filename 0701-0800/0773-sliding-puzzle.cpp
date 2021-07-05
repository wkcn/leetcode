#include "common.h"

struct Board {
  array<array<int, 3>, 2> board;
  int r_, c_;
  Board() {
  }
  Board(const vector<vector<int>> &b) {
    for (int r = 0; r < 2; ++r) {
      for (int c = 0; c < 3; ++c) {
        board[r][c] = b[r][c];
        if (b[r][c] == 0) {
          r_ = r; c_ = c;
        }
      }
    }
  }
  bool operator==(const Board &b) const {
    for (int r = 0; r < 2; ++r) {
      for (int c = 0; c < 3; ++c) {
        if (board[r][c] != b.board[r][c]) return false;
      }
    }
    return true;
  }
  friend ostream& operator<<(ostream &os, const Board &b);
};

ostream& operator<<(ostream &os, const Board &b) {
  for (int r = 0; r < 2; ++r) {
    for (int c = 0; c < 3; ++c) {
      os << b.board[r][c] << ", ";
    }
    os << endl;
  }
  return os;
}


struct BoardHasher {
  size_t operator()(const Board &b) const {
    size_t m = 0;
    for (int r = 0; r < 2; ++r) {
      for (int c = 0; c < 3; ++c) {
        m = (m << 3) | b.board[r][c];
      }
    }
    return m;
  }
};

vector<Board> opt(const Board &b) {
  vector<Board> out;
  for (auto [dr, dc] : vector<pair<int,int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
    unsigned int r = dr + b.r_; 
    unsigned int c = dc + b.c_; 
    if (r < 2 && c < 3) {
      Board t = b;
      swap(t.board[r][c], t.board[t.r_][t.c_]);
      t.r_ = r;
      t.c_ = c;
      out.emplace_back(move(t));
    }
  }
  return out;
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
      queue<Board> q1, q2;
      unordered_set<Board, BoardHasher> se1, se2;
      Board source(board);
      Board target({{1, 2, 3}, {4, 5, 0}});
      if (source == target) return 0;
      q1.push(source); se1.insert(source);
      q2.push(target); se2.insert(target);
      int step = 0;
      while (!q1.empty() && !q2.empty()) {
        ++step;
        bool b = q1.size() < q2.size() ? bfs(q1, se1, se2) : bfs(q2, se2, se1);
        if (b) return step;
      }
      return -1;
    }
    bool bfs(queue<Board> &q1, unordered_set<Board, BoardHasher> &se1, unordered_set<Board, BoardHasher> &se2) {
      int n = q1.size();
      while (n-- > 0) {
        Board b = move(q1.front()); q1.pop();
        for (Board &y : opt(b)) {
          if (se1.count(y)) continue;
          if (se2.count(y)) return true;
          q1.push(y);
          se1.insert(y);
        }
      }
      return false;
    }
};

int main() {
  if (0) {
    vector<vector<int>> board{{1,2,3},{4,0,5}};
    cout << Board(board) << endl;
    cout << Solution().slidingPuzzle(board) << endl;
  }

  if (0) {
    vector<vector<int>> board{{1,2,3},{5,4,0}};
    cout << Solution().slidingPuzzle(board) << endl;
  }

  {
    vector<vector<int>> board{{4,1,2},{5,0,3}};
    cout << Solution().slidingPuzzle(board) << endl;
  }
  return 0;
}
