#include "common.h"

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
      const int R = board.size(), C = board[0].size();
      // flatten board
      vector<int> bf{0};
      bool order = true;
      for (auto p = board.rbegin(); p != board.rend(); ++p) {
        if (order) {
          bf.insert(bf.end(), p->begin(), p->end());
        } else {
          bf.insert(bf.end(), p->rbegin(), p->rend());
        }
        order = !order;
      }
      unordered_set<int> vis;
      queue<int> q;
      q.push(1); vis.insert(1);
      int step = 0;
      while (!q.empty()) {
        ++step;
        int n = q.size();
        while (n-- > 0) {
          int from = q.front(); q.pop();
          for (int i = 1; i <= 6; ++i) {
            int to = from + i;
            if (to >= bf.size()) break;
            if (bf[to] != -1) to = bf[to];
            if (to == R * C) {
              return step;
            }
            if (vis.count(to) == 0) {
              q.push(to);
              vis.insert(to);
            }
          }
        }
      }
      return -1;
    }
};

int main() {
  vector<vector<int>> board{
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,15,-1,-1,-1,-1}};
  cout << Solution().snakesAndLadders(board) << endl;
  return 0;
}
