#include <cstdio>
#include <cstring>


const int LEN = 2000010;
typedef unsigned long long ULL;
char buf[LEN];
char S[LEN * 2 + 3];
int p[LEN * 2 + 3];
const ULL MOD = 100000007;

int main() {
  memset(p, 0, sizeof(p));
  int n;
  ULL ans = 0;
  scanf("%d", &n);
  scanf("%s", buf);
  int slen = n * 2 + 3;
  S[0] = '^';
  S[slen - 1] = '$';
  for (int i = 0; i < n; ++i) {
    S[i * 2 + 2] = buf[i];
  }
  for (int i = 1; i < slen; i += 2) {
    S[i] = '#';
  }
  // printf("%s\n", S);

  int C = 0, R = 0;
  for (int i = 2; i < slen - 2; ++i) {

    int mirror_i = 2 * C - i;
    if (mirror_i >= 0){
      int diff = R - i; 
      if (p[mirror_i] < diff){
        p[i] = p[mirror_i];
        continue;
      }
    }

    while(S[i - p[i] - 1] == S[i + p[i] + 1]) ++p[i];
    C = i;
    R = i + p[i];
  }

  for (int i = 1; i < slen; ++i) {
    ULL v = (p[i]+1) / 2;
    ans = (ans + v) % MOD; 
  }
  printf("%llu\n", ans);

  return 0;
}
