#include "common.h"

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 0;
        unsigned int b = 1 << 31;
        while (b > 0) {
          if (b & num) break;
          b >>= 1;
        }
        return (b << 1) - 1 - num;
    }
};

int main() {
  cout << Solution().findComplement(5) << endl;
  cout << Solution().findComplement(1) << endl;
  return 0;
}
