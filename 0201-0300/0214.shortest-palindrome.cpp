// TODO: manacher和KMP
#include "common.h"

class Solution {
public:
    string shortestPalindrome(string s) {
      // hash for a string
      // h(i) = h(i - 1) * base + s[i]
      // MOD
      // h(i) = (h(i - 1) * base + s[i]) % MOD
      // reverse version
      // r(i) = r(i - 1) + s[i] * (base ^ i)
      // r(i) = (r(i - 1) + s[i] * (base ^ i)) % MOD
      //      = (r(i - 1) % MOD + (s[i] * base ^ i) % MOD)
      //
      // (a × b) mod c =(a mod c * b mod c) mod c
      // 证明: 假设a = c * m + t, b = c * n + u
      // (a * b) % c = (t * u) % c = (a % c) * (b % c)
      int h = 0;
      int r = 0;
      const int BASE = 26;
      const int MOD = 40000217;
      int base = 1;
      int j = -1;
      for (int i = 0; i < s.size(); ++i) {
        const int v = s[i] - 'a';
        h = ((long long)h * BASE + v) % MOD;
        r = (r + (long long)v * base) % MOD;
        if (h == r) {
          j = i;
        }
        base = ((long long)base * BASE) % MOD;
      }
      // reverse [j+1, s.size())
      const int len = s.size() - (j + 1);
      return string(s.rbegin(), s.rbegin() + len) + s;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().shortestPalindrome(s) << endl;
  return 0;
}
