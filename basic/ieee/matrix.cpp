#include <cstdio> 
#include <cstring>
#include <iostream>
using namespace std;

const int LEN = 100000;

typedef unsigned long long ULL;
const ULL MOD = 1e9+7;

ULL A[LEN + 10];
ULL B[LEN + 10];

ULL fact[LEN * 2];

ULL fastpower(ULL value, ULL n) {
  if (n == 0) return 1;
  if (n == 1) return value  % MOD;
  ULL w = fastpower((value * value) % MOD, n / 2);
  if (n & 1) w *= value;
  return w % MOD;
}


ULL comb(ULL n, ULL m) {
  // return fact[n] / fact[m] / fact[n-m];
  if (n == m || m == 0) return 1;
  return (fact[n] * fastpower(fact[m], MOD-2) % MOD) * fastpower(fact[n-m], MOD-2) % MOD; 
}


int main() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < LEN * 2; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  int T;
  scanf("%d", &T);
  ULL a;
  int n;
  for (int t = 1; t <= T; ++t) {
    scanf("%llu %d", &a, &n);
    ULL head;// (1, 1)
    for (int i = 0; i < n; ++i) {
      scanf("%llu", A + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%llu", B + i);
    }
    ULL ans = 0;
    if (n == 1) {
      ans = A[0];
    } else {
      ULL C = 1;
      ULL AP = fastpower(a, n-1);
      for (int k = 1; k < n; ++k) {
        int u = n - k;
        ULL iv = ((C * AP) % MOD * (A[u] + B[u])) % MOD;
        ans = (ans + iv) % MOD;
        C = comb(n + k - 2, n - 2);
        AP = (AP * a) % MOD;
      }
    }
    printf("case %d: ", t);
    printf("%llu\n", ans);
  }
  return 0;
}
