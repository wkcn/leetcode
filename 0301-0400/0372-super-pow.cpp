#include "common.h"

class Solution {
public:
    int superPow(int a, vector<int>& b) {
      const int MOD = 1337;
      int y = 1;
      a %= MOD;
      reverse(b.begin(), b.end());
      while (b.size() > 1 || b[0] > 0) {
        if (b[0] & 1) {
          y = (y * a) % MOD;
        }
        a = (a * a) % MOD;
        // div b by 2
        bool c = false;
        for (int i = int(b.size()) - 1; i >= 0; --i) {
          if (c) b[i] += 10;
          c = b[i] & 1;
          b[i] >>= 1;
        }
        while (!b.empty() && b.back() == 0) b.pop_back();
      }
      return y;
    }
};

int main() {
  int a = 2147483647;
  vector<int> b = {2, 0, 0};
  cout << Solution().superPow(a, b) << endl;
  return 0;
}
