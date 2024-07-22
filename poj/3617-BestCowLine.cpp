#include <cstdio>
int S[2001];
int T[2001];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c; scanf(" %c", &c);
    S[i] = c;
  }
  int i = 0, j = n - 1;
  int y = 0;
  while (i <= j) {
    // (i, j), r
    // (2, 2), 0
    // (2, 3), 0
    // (2, 4), 0
    // (2, 5), 1
    // (2, 6), 1
    int r = (j - i - 1) / 2;
    bool left = true;
    for (int k = 0; k <= r; ++k) {
      if (S[i + k] < S[j - k]) {
        left = true;
        break;
      } else if (S[i + k] > S[j - k]) {
        left = false;
        break;
      }
    }
    if (left) {
      T[y++] = S[i++];
    } else {
      T[y++] = S[j--];
    }
  }
  for (int i = 0; i < y; ++i) {
    if (i % 80 == 0 && i > 0) putchar('\n');
    putchar(T[i]);
  }
  putchar('\n');
  return 0;
};
