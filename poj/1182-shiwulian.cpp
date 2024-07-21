// 食物链
#include <cstdio>

#include <vector>
#include <numeric>
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

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  UnionFind uf(3 * n);
  int ans = 0;
  int t, x, y;
  for (int i = 0; i < k; ++i) {
    scanf("%d %d %d", &t, &x, &y);
    x -= 1;
    y -= 1;
    if (t < 1 || t > 2 || x < 0 || x >= n || y < 0 || y >= n) {
      ++ans;
      continue;
    }
    if (t == 1) {
      if (uf.same(x, y + n) || uf.same(x, y + 2 * n)) {
        ++ans;
      } else {
        uf.unite(x, y);
        uf.unite(x + n, y + n);
        uf.unite(x + 2 * n, y + 2 * n);
      }
    } else {
      if (uf.same(x, y) || uf.same(x, y + 2 * n)) {
        ++ans;
      } else {
        uf.unite(x, y + n);
        uf.unite(x + n, y + 2 * n);
        uf.unite(x + 2 * n, y);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
