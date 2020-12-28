#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
  pair<int, int> car;
  pair<int, int> empty;
  bool operator<(const State &b) const {
    if (car != b.car) return car < b.car;
    return empty < b.empty;
  }
};

int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solve(int m, int n) {
  State state{{0, 0}, {m - 1, n - 1}};
  map<State, int> ma;
  ma[state] = 0;
  queue<State> q; q.push(state);
  while (!q.empty()) {
    State s = q.front(); q.pop();
    int step = ma[s];
    if (s.car.first == m - 1 && s.car.second == n - 1) {
      return ma[s];
    }
    for (int d = 0; d < 4; ++d) {
      unsigned int nr = s.empty.first + DIRS[d][0];
      unsigned int nc = s.empty.second + DIRS[d][1];
      if (nr < m && nc < n) {
        State ns{{s.car.first, s.car.second}, {nr, nc}};
        if (s.car.first == nr && s.car.second == nc) {
          ns.car.first = s.empty.first;
          ns.car.second = s.empty.second;
        }
        auto ret = ma.insert({ns, step + 1});
        if (ret.second) q.push(ns);
      }
    }
  }
  return -1;
}

int main() {
  int m, n;
  cin >> m >> n;
  cout << solve(m, n) << endl;
  return 0;
}
