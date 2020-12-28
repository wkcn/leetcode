#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> isP(20 * 20, false);
vector<int> buf;

bool go(queue<int> &q) {
  const int s = q.size();
  if (s == 1) {
    int v = q.front();
    return (isP[buf.back() + v] && isP[buf.front() + v]);
  } else {
    for (int i = 0; i < s; ++i) {
      int v = q.front(); q.pop();
      if (isP[buf.back() + v]) {
        buf.push_back(v);
        if (go(q)) return true;
        buf.pop_back();
      }
      q.push(v);
    }
  }
  return false;
}

bool check(int n) {
  // [1, n]
  buf.push_back(1);
  queue<int> q;
  for (int i = 2; i <= n; ++i) q.push(i);
  return go(q);
}

int main() {
  for (int i = 1; i < 20; ++i) {
    isP[i * i] = true;
  }
  int N = 2;
  while (1) {
    if (check(N)) {
      cout << N << endl;
      break;
    }
    ++N;
  }
  return 0;
}
