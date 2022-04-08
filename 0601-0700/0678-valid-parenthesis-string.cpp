#include "common.h"

// TODO: 为什么统计left和star数量的方案不行
class Solution {
public:
    bool checkValidString(string s) {
      int hi = 0, lo = 0;
      for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
          case '(':
            ++hi; ++lo;
            break;
          case '*':
            lo = max(lo - 1, 0);
            ++hi;
            break;
          case ')':
            if (--hi < 0) return false;
            lo = max(lo - 1, 0);
            break;
        };
      }
      return lo == 0;
    }
};

int main() {
  while (1) {
    string s; cin >> s;
    cout << Solution().checkValidString(s) << endl;
  }
  return 0;
}
