#include "common.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<int> co(n, 1);
      while (--m) {
        for (int i = 0; i < n; ++i) {
          if (i > 0) {
            co[i] += co[i - 1]; 
          }
        }
      }
      return co.back();
    }
};

int main() {
  int m, n;
  cin >> m >> n;
  cout << Solution().uniquePaths(m, n) << endl;
  return 0;
}
