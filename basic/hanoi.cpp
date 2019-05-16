#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

struct State {
  vector<int> data[3];
  bool operator<(const State& b) const {
    for (int i = 0; i < 3; ++i) {
      if (data[i].size() != b.data[i].size()) return data[i].size() < b.data[i].size();
    }
    for (int i = 0; i < 3; ++i) {
      const vector<int> &va = data[i];
      const vector<int> &vb = b.data[i];
      for (auto pa = va.begin(), pb = vb.begin(); pa != va.end(); ++pa, ++pb) {
        if (*pa != *pb) return *pa < *pb;
      }
    }
    return false;
  }
};


bool check(State &state) {
  if (state.data[0].empty() && state.data[1].empty()) {
    int u = 1;
    for (auto p = state.data[2].rbegin(); p != state.data[2].rend(); ++p) {
      if (*p != u++) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  int n, m;
  State start;
  for (int r = 0; r < 3; ++r) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &m);
      start.data[r].push_back(m);
    }
  }

  set<State> se;
  queue<pair<int, State> > q;
  q.push({0, start});

  int step = -1;
  while (!q.empty()) {
    pair<int, State> p = q.front(); q.pop();
    State &state = p.second;
    if (se.count(state)) {
      continue;
    }

    /*

      cout << "==========" << endl;
      for (int i = 0; i < 3; ++i) {
        for (int e : state.data[i]) {
          cout << e << ", ";
        }
        cout << endl;
      }
    */


    if (check(state)) {
      // OOOO
      step = p.first;
      break;
    }
    se.insert(state);

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i != j) {
          // i -> j
          if (state.data[i].size() > 0 && (state.data[j].empty() || state.data[i].back() < state.data[j].back())) {
            State new_state = state;
            int v = new_state.data[i].back();
            new_state.data[j].push_back(v);
            new_state.data[i].pop_back();
            q.push({p.first + 1, new_state});
          }
        }
      }
    } 
  }

  if (step < 0) {
    printf("No\n");
  } else {
    printf("%d\n", step);
  }

  return 0;
}
