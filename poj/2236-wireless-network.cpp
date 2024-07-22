#include <cstdio>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    parents.resize(n);
    // iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < n; ++i) parents[i] = i;
    ranks.resize(n, 0);
  }
  int find(int x) {
    int t = x;
    while (parents[t] != t) {
      t = parents[t];
    }
    parents[x] = t;
    return t;
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (ranks[x] < ranks[y]) {
      parents[x] = y;
    } else {
      parents[y] = x;
      if (ranks[x] == ranks[y]) {
        ++ranks[x];
      }
    }
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
private:
  vector<int> parents;
  vector<int> ranks;
};

typedef pair<int, int> P;

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<P> ps;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    ps.push_back({x, y});
  }
  UnionFind uf(n);
  char c;
  vector<int> repair;
  while (scanf(" %c", &c) == 1) {
    if (c == 'O') {
      int t; scanf("%d", &t);
      --t;
      for (int i = 0; i < repair.size(); ++i) {
        int u = repair[i];
        if (u != t) {
          int dx = ps[u].first - ps[t].first;
          int dy = ps[u].second - ps[t].second;
          if (dx * dx + dy * dy <= d * d)
            uf.unite(t, u);
        }
      }
      repair.push_back(t);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      --a; --b;
      if (uf.same(a, b)) {
        printf("SUCCESS\n");
      } else printf("FAIL\n");
    } 
  }
  return 0;
}
