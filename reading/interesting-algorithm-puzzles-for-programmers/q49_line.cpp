#include "common.h"

int solve2(int n, int m) {
  ++n, ++m;
  vector<int> rows(n, 0), cols(m, 0);
  const int T = 2;
  int ans = 0;
  vector<pair<int, int> > best_path; 
  vector<pair<int, int> > buf;
  buf.push_back({0, 0});
  function<void(unsigned int, unsigned int, int)> F = \
    [&](unsigned int r, unsigned int c, int step) {
      if (r == n - 1 && c == m - 1) {
        // 最终到达节点B
        if (step > ans) best_path = buf;
        ans = max(ans, step);
      }
      for (int d : {-1, 1}) {
        if (r + d < n && cols[c] < T) {
          ++cols[c];
          buf.push_back({r + d, c});
          F(r + d, c, step + 1);
          buf.pop_back();
          --cols[c];
        }
        if (c + d < m && rows[r] < T) {
          ++rows[r];
          buf.push_back({r, c + d});
          F(r, c + d, step + 1);
          buf.pop_back();
          --rows[r];
        }
      }
    };
  F(0, 0, 0);
  for (auto [r, c] : best_path) {
    cout << r << ", " << c << endl;
  }
  return ans;
}

int solve(int n, int m) {
  ++n, ++m;
  vector<int> rows(n, 0), cols(m, 0);
  const int T = 2;  // 每条线上行走的最大次数
  int ans = 0;
  function<void(unsigned int, unsigned int, int)> F = \
    [&](unsigned int r, unsigned int c, int step) {
      if (r == n - 1 && c == m - 1) {
        // 最终到达节点B
        ans = max(ans, step);
      }
      for (int d : {-1, 1}) {
        if (r + d < n && cols[c] < T) {
          ++cols[c];
          F(r + d, c, step + 1);
          --cols[c];
        }
        if (c + d < m && rows[r] < T) {
          ++rows[r];
          F(r, c + d, step + 1);
          --rows[r];
        }
      }
    };
  F(0, 0, 0);
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}
