#include "common.h"

class Solution {
public:
    int climbStairs(int n) {
      int h2 = 1;
      int h1 = 1;
      int v = 1;
      while (--n) {
        v = h2 + h1;
        h2 = h1;
        h1 = v;
      } 
      return v;
    }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().climbStairs(n) << endl;
  return 0;
}
