#include "common.h"

// TODO: 其他求素数的方法
//
#define SOLUTION 3

#if SOLUTION == 1
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> ps{2};
        for (int i = 3; i < n; i += 2) {
            int h = sqrt(i);
            bool fail = false;
            for (int v : ps) {
                if (v > h) break;
                if (i % v == 0) {
                    fail = true;
                    break;
                }
            }
            if (!fail) ps.push_back(i);
        }
        return ps.size();
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ps(n, 0);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (!ps[i]) {
                ps[i] = true;
                ++ans;
                // [i * i, i * (i + 1), i * (i + 2), ..]
                // i * i有可能溢出
                // i * i < n
                // i < float(n) / float(i)
                if (i <= n / i) {
                    for (int t = i * i; t < n; t += i) {
                        ps[t] = true;
                    }
                }
            }
        }
        return ans;
    }
};

#elif SOLUTION == 3

class Solution {
public:
    int countPrimes(int n) {
      vector<bool> vis(n, 0);
      vector<int> ps;
      for (int i = 2; i < n; ++i) {
        if (!vis[i]) {
          ps.push_back(i);
        }
        for (int x : ps) {
          if (x > n / i) break;
          vis[x * i] = true;
          if (i % x == 0) break;
        }
      }
      return ps.size();
    }
};

#endif

int main() {
  int n; cin >> n;
  cout << Solution().countPrimes(n) << endl;
  return 0;
}
