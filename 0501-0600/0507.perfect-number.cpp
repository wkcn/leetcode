// 算因子，开根号！
#include "common.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int su = 1;
        const int r = sqrt(num);
        for (int i = 2; i <= r; ++i) if (num % i == 0) su += i + num / i;
        if (r * r == num) su -= r;
        return su == num;
    }
};

int main() {
  int num; cin >> num;
  cout << Solution().checkPerfectNumber(num) << endl;
  return 0;
}
