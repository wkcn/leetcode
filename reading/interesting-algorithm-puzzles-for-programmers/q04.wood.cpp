#include <iostream>
#include <queue>

using namespace std;

int solve(int n, int m) {
  if (n <= 1) return 0;
  priority_queue<int> q;
  q.push(n);
  int t = 0;
  while (!q.empty()) {
    ++t;
    const int R = min(m, (int)q.size());
    queue<int> cur_q;
    for (int r = 0; r < R; ++r) {
      int v = q.top(); q.pop();
      int half = v / 2;
      cur_q.push(half);
      cur_q.push(v - half);
    }
    while (!cur_q.empty()) {
      int v = cur_q.front(); cur_q.pop();
      if (v > 1) q.push(v);
    }
  }
  return t;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}
