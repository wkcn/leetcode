// TODO: 要灵活使用位运算，预先计算匹配对！！！！！
// 目前的解法不灵活！
#include "common.h"

// 多源BFS, 从最终状态开始搜索
// 状态压缩
inline int P(int cols, int r, int c) {
  return cols * r + c;
}

inline void Set1b(int &v, int p) {
  v |= (1 << p);
}

inline void Set0b(int &v, int p) {
  v &= ~(1 << p);
}

inline bool Get(int &v, int p) {
  return v & (1 << p);
}

vector<int> GetFinalStates(int rows, int cols) {
  vector<int> out(4, 0);
  for (int c = 0; c < cols; ++c) {
    for (int r = 0; r < rows / 2; ++r) {
      Set1b(out[0], P(cols, r, c));
    }
    for (int r = rows / 2; r < rows; ++r) {
      Set1b(out[1], P(cols, r, c));
    }
  }
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols / 2; ++c) {
        Set1b(out[2], P(cols, r, c));
    }
    for (int c = cols / 2; c < cols; ++c) {
        Set1b(out[3], P(cols, r, c));
    }
  }
  return out;
}

const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int Solve(int rows, int cols) {
  assert (rows * cols <= 32);
  vector<int> states = GetFinalStates(rows, cols);
  unordered_set<int> vis;
  queue<int> q;
  for (int s: states) {
    q.push(s);
    vis.insert(s);
  }
  int ans = 0;
  while (!q.empty()) {
    const int qsize = q.size();
    for (int e = 0; e < qsize; ++e) {
      int s = q.front(); q.pop();
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          int p = P(cols, r, c);
          if (Get(s, p)) {
            for (auto [dr, dc] : DIRS) {
              unsigned int nr = r + dr;
              unsigned int nc = c + dc;
              if (nr < rows && nc < cols) {
                int np = P(cols, nr, nc);
                if (!Get(s, np)) {
                  int ns = s ^ (1 << p | 1 << np);
                  if (vis.insert(ns).second) {
                    q.push(ns);
                  }
                }
              }
            }
          }
        }
      }
    }
    // 说明能走一步
    if (q.size() == 0) {
      ans = qsize;
    }
  }
  return ans;
}

int main() {
  int rows, cols;
  cin >> rows >> cols;
  cout << Solve(rows, cols) << endl;
  return 0;
}
