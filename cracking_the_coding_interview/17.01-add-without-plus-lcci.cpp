#include "common.h"

#define SOLUTION 1 

#if SOLUTION == 1
class Solution {
public:
    int add(int a, int b) {
        // 无符号！
        unsigned int ub = b;
        unsigned int ua = a;
        unsigned int uc = 0;
        // 注意b == 0的情况
        while (ub) {
            uc = ua ^ ub;
            ub = (ua & ub) << 1;
            ua = uc;
        };
        // 只能返回ua而不是uc, 例子ub == 0
        return ua;
    }
};
#elif SOLUTION == 2

class Solution {
public:
    int add(int a, int b) {
        unsigned int ub = b;
        unsigned int ua = a;
        unsigned int uc;
        while (ub) {
            uc = (ua & ub) << 1;
            ua = ua ^ ub;
            ub = uc;
        };
        return ua;
    }
};
#endif

int main() {
  int a, b;
  cin >> a >> b;
  cout << Solution().add(a, b) << endl;
  return 0;
}
