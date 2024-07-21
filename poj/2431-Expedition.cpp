#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector<pair<int, int> > vs(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    vs[i] = pair<int, int>{a, b};
  }
  int L, P;
  scanf("%d%d", &L, &P);
  for (int i = 0; i < n; ++i) {
    vs[i] = pair<int, int>{L - vs[i].first, vs[i].second};
  }
  sort(vs.begin(), vs.end());
  priority_queue<int> pq;
  int p = P;
  int cnt = 0;
  int i = 0;
  while (p < L) {
    // 注意i < vs.size()的位置，即使它遍历完了，pq中可能还有元素
    if (i < vs.size() && p >= vs[i].first) {
      pq.push(vs[i].second);
      ++i;
    } else {
      if (pq.empty()) break;
      p += pq.top();
      ++cnt;
      pq.pop();
    }
  }
  if (p < L) printf("-1\n");
  else printf("%d\n", cnt);
  return 0;
}
