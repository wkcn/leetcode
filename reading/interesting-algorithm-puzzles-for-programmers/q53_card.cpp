#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
void go(int i, vector<int> &buf, vector<bool> &used, int &ans) {
  if (i >= buf.size()) {
    ++ans;
    return;
  }
  if (buf[i] != -1) {
    go(i + 1, buf, used, ans);
    return;
  }
  // 1 to n
  // 1444ms
  // for (int j = 1; j < used.size(); ++j) {
  // 818ms
  for (int j = used.size() - 1; j >= 1; --j) {
    if (!used[j]) {
      int p = i + j + 1;
      if (p < buf.size() && buf[p] == -1) {
        used[j] = true;
        buf[i] = j; buf[p] = j;
        go(i + 1, buf, used, ans);
        buf[i] = buf[p] = -1;
        used[j] = false;
      }
    }
  }
}

int solve(int n) {
  vector<int> buf(2 * n, -1);
  vector<bool> used(n + 1, 0);
  int ans = 0;
  go(0, buf, used, ans);
  return ans;
}

#elif SOLUTION == 2

void go(int i, vector<int> &buf, int &ans) {
  if (i == 0) {
    ++ans;
    return;
  }
  for (int j = 0; j < buf.size(); ++j) {
    if (buf[j] == -1) {
      int p = i + j + 1;
      if (p < buf.size() && buf[p] == -1) {
        buf[j] = buf[p] = i;
        go(i - 1, buf, ans);
        buf[j] = buf[p] = -1;
      }
    }
  }
}

// 401 ms
int solve(int n) {
  vector<int> buf(2 * n, -1);
  int ans = 0;
  go(n, buf, ans);
  return ans;
}

#endif

int main() {
  int n;
  cin >> n;
  Timer timer;
  timer.tic();
  cout << solve(n) << endl;
  timer.toc();
  return 0;
}
