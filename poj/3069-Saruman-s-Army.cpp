#include <cstdio>
#include <algorithm>
using namespace std;

int D[1001];

bool solve() {
  int R, n;
  scanf("%d %d", &R, &n);
  if (R == -1) return false;
  if (n == 0) {
    printf("0\n");
    return true;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", D + i); 
  }
  sort(D, D + n);
  int i = 0;
  int cnt = 0;
  while (i < n) {
    int j = i + 1;
    for (;j < n; ++j) {
      if (D[j] - D[i] > R) {
        break;
      }
    }
    // mark j - 1
    for (i = j; i < n; ++i) {
      if (D[i] - D[j - 1] > R) break;
    }
    ++cnt;
  }
  printf("%d\n", cnt);

  return true;
}

int main() {
  while (solve()) {
  }
  return 0;
}
