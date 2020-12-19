// TODO: 还有其他的拆分方法
#include "common.h"

class Solution {
public:
    const int MOD = 1337;
    int superPow(int a, vector<int>& b) {
      if (b.empty()) return 1;
      if (b.size() == 1) {
        if (b[0] == 0) return 1;
        if (b[0] == 1) return a % MOD;
      }
      int y = div2(b);
      int h = superPow(a % MOD, b);
      h = (h * h) % MOD;
      if (y == 1) h = (h * (a % MOD)) % MOD;
      return h;
    }
    int div2(vector<int> &e) {
        int i = 0;
        int v = 0;
        bool first = true;
        for (int j = 0; j < e.size(); ++j) {
            v = v * 10 + e[j];
            int y = v / 2;
            if (y > 0 || !first) {
              e[i++] = y;
              first = false;
            }
            v %= 2;
        }
        e.resize(i);
        return v;
    }
};

int main() {
  int a; vector<int> b;
  cin >> a; INPUT_ARRAY(b);
  cout << Solution().superPow(a, b) << endl;
  return 0;
}
