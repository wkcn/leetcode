#include "common.h"

int mygcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
      return fraction(0, cont);
    }
    vector<int> fraction(int start, vector<int>& cont) {
      if (start == cont.size() - 1) return {cont[start], 1};
      vector<int> b = fraction(start + 1, cont);
      swap(b[0], b[1]);
      b[0] += b[1] * cont[start];
      // 可以去掉GCD
      /*
      int c = mygcd(b[0], b[1]);
      b[0] /= c;
      b[1] /= c;
      */
      return b;
    }
};
#elif SOLUTION == 2

class Solution {
public:
  vector<int> fraction(vector<int>& cont) {
    int up = cont.back(), down = 1;
    for (int t = (int)cont.size() - 2; t >= 0; --t) {
      swap(down, up);
      up += down * cont[t];
    }
    return {up, down};
  }
};

#endif

int main() {
  vector<int> cont;
  INPUT_ARRAY(cont);
  PRINT_ARRAY(Solution().fraction(cont));
  return 0;
}
