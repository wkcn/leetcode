#include "common.h"

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
  int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0) return 0;
    vector<vector<bool> > vis(rows, vector<bool>(cols, false));
    stack<pair<int, int> > st;
    st.push({0, 0});
    vis[0][0] = true;
    int cnt = 1;
    while (!st.empty()) {
      pair<int, int> p = st.top(); st.pop();
      for (int d = 0; d < 4; ++d) {
        int nr = p.first + dir[d][0];
        int nc = p.second + dir[d][1];
        if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
          if (!vis[nr][nc] && get_w(nr) + get_w(nc) <= threshold) {
            vis[nr][nc] = true;
            ++cnt;
            st.push({nr, nc});
          }
        }
      }
    }
    return cnt;
  }
private:
  int get_w(int v) {
    int e = 0;
    while (v > 0) {
      e += v % 10;
      v /= 10;
    }
    return e;
  }
};

int main() {
  int threshold, rows, cols;
  cin >> threshold >> rows >> cols;
  cout << Solution().movingCount(threshold, rows, cols) << endl;
  return 0;
}
