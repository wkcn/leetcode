#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long LL;
int main() {
  int n;
  scanf("%d", &n);
  priority_queue<LL, vector<LL>, greater<LL> > q;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    q.push(x);
  }
  LL ans = 0;
  while (q.size() > 1) {
    LL a = q.top(); q.pop();
    LL b = q.top(); q.pop();
    q.push(a + b);
    ans += a + b;
  }
  printf("%lld\n", ans);
  return 0;
}
