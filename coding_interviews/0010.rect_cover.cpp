#include "common.h"

class Solution {
public:
  int rectCover(int number) {
    if (number <= 2) return number;
    int pre2 = 1;
    int pre1 = 2;
    for (int i = 2; i < number; ++i) {
      int cur = pre1 + pre2;
      pre2 = pre1;
      pre1 = cur;
    }
    return pre1;
  }
};

int main() {
  int n;
  cin >> n;
  cout << Solution().rectCover(n) << endl;
  return 0;
}
