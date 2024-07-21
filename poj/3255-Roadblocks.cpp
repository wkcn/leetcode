#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  vector<vector<P> > G(n);
  for (int i = 0; i < r; ++i) {
    int x, y, v;
    scanf("%d %d %d", &x, &y, &v);
    // 双向
    G[x-1].push_back(P(y-1, v));
    G[y-1].push_back(P(x-1, v));
  }
  priority_queue<P, vector<P>, greater<P> > pq;
  int CINF = 1e9;
  vector<int> dist(n, CINF);
  vector<int> dist2(n, CINF);
  dist[0] = 0;
  pq.push(P(0, 0));
  while (!pq.empty()) {
    P p = pq.top(); pq.pop();
    int d = p.first, t = p.second;
    if (dist2[t] < d) continue;
    for (int i = 0; i < G[t].size(); ++i) {
      P &y = G[t][i];
      int d2 = d + y.second;
      if (d2 < dist[y.first]) {
        swap(d2, dist[y.first]);
        pq.push(P(dist[y.first], y.first));
      }
      if (dist2[y.first] > d2 && dist[y.first] < d2) {
        dist2[y.first] = d2;
        pq.push(P(dist2[y.first], y.first));
      }
    }
  }
  printf("%d\n", dist2[n-1]);
  return 0;
}
