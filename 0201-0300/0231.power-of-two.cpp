#include "common.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
      // 注意<=0的情况
      if (n <= 0) return false;
      // 注意优先级！！
      return (n & (n - 1)) == 0;
    }
};

int main() {
  int n; cin >> n;
  cout << Solution().isPowerOfTwo(n) << endl;
  return 0;
}
