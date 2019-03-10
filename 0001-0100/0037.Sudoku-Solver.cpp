#include "common.h"

inline int grid_id(int r, int c) {
  const int gr = r / 3, gc = c / 3;
  return gr * 3 + gc;
}

class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    short valid[3][9];
    memset(valid, 0xFF, sizeof(valid));
    using pos_t = pair<int, int>;
    vector<pos_t> pos;
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        char cv = board[r][c];
        if (cv != '.') {
          int val = cv - '0';
          fill(valid, r, c, val);
        } else {
          pos.push_back({r, c});
        }
      }
    }
    vector<vector<int> > vfs(pos.size());
    for (int i = 0;i < pos.size();++i) {
      pos_t &p = pos[i];
      int &r = p.first, &c = p.second;
      int g = grid_id(r, c);
      for (int u = 1; u <= 9; ++u) {
        int b = 1 << u;
        if ((valid[0][r] & b) && (valid[1][c] & b) && (valid[2][g] & b)) vfs[i].push_back(u);
      }
    }

    // sort for pos and vfs
    sort_for_pos_and_vfs(pos, vfs);

    int m = vfs.size();
    vector<int> seq(m);

    int q = 1;
    fill(valid, pos[0].first, pos[0].second, vfs[0][0]);
    seq[0] = 0;

    while (q >= 1 && q < m) {
      pos_t &p = pos[q];
      vector<int> &option = vfs[q];
      bool pushed = false;
      int &r = p.first, &c = p.second; 
      for (int w = 0; w < option.size(); ++w) {
        int &v = option[w];
        if (is_valid(valid, r, c, v)) {
          seq[q++] = w;
          pushed = true;
          fill(valid, r, c, v);
          break;
        }
      }
      if (pushed) continue;
      // backtrack
      while (q >= 1) {
        int back = q - 1;
        vector<int> &back_opt = vfs[back];
        pos_t &back_p = pos[back];
        int &back_r = back_p.first, &back_c = back_p.second;
        int &back_vi = seq[back];
        unfill(valid, back_r, back_c, back_opt[back_vi]); 
        while (++back_vi < back_opt.size()) {
          int back_new_v = back_opt[back_vi];
          if (is_valid(valid, back_r, back_c, back_new_v)) {
            fill(valid, back_r, back_c, back_new_v);
            break;
          }
        }
        if (back_vi >= back_opt.size()) {
          --q;
        } else break;
      }
    }
    for (int i = 0; i < m; ++i) {
      pos_t &p = pos[i];
      const int v = vfs[i][seq[i]];
      board[p.first][p.second] = v + '0';
    }
  }
private:
  inline void unfill(short valid[3][9], int r, int c, int v) {
    short b = 1 << v;
    int g = grid_id(r, c);
    valid[0][r] |= b;
    valid[1][c] |= b;
    valid[2][g] |= b;
  }
  inline void fill(short valid[3][9], int r, int c, int v) {
    short b = ~(1 << v);
    int g = grid_id(r, c);
    valid[0][r] &= b;
    valid[1][c] &= b;
    valid[2][g] &= b;
  }
  inline bool is_valid(short valid[3][9], int r, int c, int v) {
    short b = 1 << v;
    return (valid[0][r] & valid[1][c] & valid[2][grid_id(r, c)] & b);
  }
  struct comp_with_value {
    comp_with_value(int *data) : data_(data) {
    } 
    bool operator()(int i, int j) {
      return data_[i] < data_[j];
    }
    int *data_;
  };
  template <typename T>
  inline void reorder(const vector<int> &idx, T &data) {
    T tmp(data.size());
    for (int i = 0; i < idx.size(); ++i) {
      tmp[i] = data[idx[i]];
    }
    data = std::move(tmp);
  } 
  inline void sort_for_pos_and_vfs(vector<pair<int, int> > &pos, vector<vector<int> > &vfs) {
    const int m = vfs.size();
    vector<int> idx(m);
    vector<int> siz(m);
    for (int i = 0; i < m; ++i) {
      idx[i] = i;
      siz[i] = vfs[i].size();
    }
    std::sort(idx.begin(), idx.end(), comp_with_value(siz.data()));
    reorder(idx, pos);
    reorder(idx, vfs);
  }
};

int main() {
  Timer timer;
  const int N = 1000;
  for (int i = 0; i < N; ++i) {
  string board_str[9] = {"53..7....",
                     "6..195...",
                     ".98....6.",
                     "8...6...3",
                     "4..8.3..1",
                     "7...2...6",
                     ".6....28.",
                     "...419..5",
                     "....8..79"};
  vector<vector<char> > board(9, vector<char>(9));
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      board[r][c] = board_str[r][c];
    }
  }
  Solution().solveSudoku(board);
  //PRINT_MATRIX(board);
  }
  timer.toc();
  return 0;
}
