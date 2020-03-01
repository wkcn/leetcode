#include "common.h"

struct Flag {
  const int n;
  vector<bool> row, col, leftdown, rightdown;
  vector<string> data;
};

class Solution {
public:
    using Pos = array<int, 2>;
    vector<vector<string>> solveNQueens(int n) {
      if (n == 0) return {};
      if (n == 1) return {{"Q"}}; // 注意大循环里没有考虑n==1
      vector<vector<string> > ans;
      Flag flag{
        n,
        vector<bool>(n, false),
        vector<bool>(n, false),
        vector<bool>(2 * n + 1, false),
        vector<bool>(2 * n + 1, false),
        vector<string>(n, string(n, '.')),
      };
      stack<Pos> st;
      st.push({0, 0});
      SetQueen({0, 0}, flag, true);
      while (!st.empty()) {
        // try to push next queue
        Pos &p = st.top();
        // 以p为开始状态，先尝试放下一行
        bool valid = false;
        for (int i = 0; i < n; ++i) {
          if (CheckQueen({p[0]+1, i}, flag)) {
            if (st.size() == n - 1) {
              // 最后一行
              vector<string> ma = flag.data;
              ma[p[0]+1][i] = 'Q';
              ans.emplace_back(ma);
            } else {
              SetQueen({p[0]+1, i}, flag, true);
              valid = true;
              st.push({p[0]+1, i});
            }
            break;
          }
        }
        if (!valid) {
          // 当前状态步进
          while (!st.empty()) {
            Pos &r = st.top();
            SetQueen(r, flag, false);
            while (++r[1] < n) {
              // r更新后需要判断
              if (CheckQueen(r, flag)) {
                SetQueen(r, flag, true);
                break;
              } 
            }
            if (r[1] < n) break;
            else {
              st.pop();
            }
          }
        }
      }
      return ans;
    }
    void SetQueen(Pos p, Flag &flag, bool b) {
      /*
       * n = 3
       * (0, 0) (0, 1) (0, 2)
       * (1, 0) (1, 1) (1, 2)
       * (2, 0) (2, 1) (2, 2)
       */
      // p[0] - p[1]: [1-n, n-1]
      // p[0] + p[1]: [0, 2n-2]
      flag.row[p[0]] = b;
      flag.col[p[1]] = b;
      flag.leftdown[p[0] + p[1]] = b;
      flag.rightdown[p[0] - p[1] + flag.n - 1] = b;
      flag.data[p[0]][p[1]] = b ? 'Q' : '.';
    }
    bool CheckQueen(Pos p, Flag &flag) {
      return !(flag.row[p[0]] ||
        flag.col[p[1]] ||
        flag.leftdown[p[0] + p[1]] ||
        flag.rightdown[p[0] - p[1] + flag.n - 1]);
    }
};

int main() {
  int n;
  cin >> n;
  for (vector<string> &vs : Solution().solveNQueens(n)) {
    for (string &s : vs) {
      cout << s << endl;
    }
    cout << "=====" << endl;
  }
  return 0;
}
