#include "common.h"

// TODO: 给定排序求n
class Solution {
public:
    string getPermutation(int n, int k) {
      /*
       * n = 3
       * 0: 123
       * 1: 132
       * 2: 213
       * 3: 231
       * 4: 312
       * 5: 321
       */
      vector<int> count(n);
      count[0] = 1;
      for (int i = 1; i < n; ++i) {
        count[i] = count[i - 1] * i;
      }
      // n = 3, count = {1, 1, 2}
      vector<int> rest(n);
      iota(rest.begin(), rest.end(), 1);
      string out;
      --k;
      for (int i = 0; i < n; ++i) {
        int y = count[n - 1 - i];
        int d = k / y;
        out += to_string(rest[d]);
        rest.erase(rest.begin() + d);
        k %= y;
      } 
      return out;
    }
};

int main() {
  int n, k;
  cin >> n >> k;
  cout << Solution().getPermutation(n, k) << endl;
  return 0;
}
