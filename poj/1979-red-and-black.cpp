#include <queue>
#include <cstdio>
#include <utility>
using namespace std;

char M[21][21];
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  int W, H;
  while (scanf("%d %d", &W, &H) && W > 0 && H > 0) {
    for (int r = 0; r < H; ++r) {
      scanf("%s", M[r]);
    }
    int sr, sc;
    for (int r = 0; r < H; ++r) {
      for (int c = 0; c < W; ++c) {
        if (M[r][c] == '@') {
          sr = r; sc = c;
          break;
        }
      }
    }
    queue<pair<int, int> > q;
    q.push({sr, sc});
    M[sr][sc] = '#';
    int ans = 0;
    while (!q.empty()) {
      pair<int, int> p = q.front(); q.pop();
      ++ans;
      int r = p.first, c = p.second;
      for (int d = 0; d < 4; ++d) {
        unsigned int nr = r + dirs[d][0];
        unsigned int nc = c + dirs[d][1];
        if (nr < H && nc < W && M[nr][nc] == '.') {
          M[nr][nc] = '#';
          q.push({nr, nc});
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
