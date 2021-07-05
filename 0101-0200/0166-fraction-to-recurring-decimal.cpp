#include "common.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      // 注意
      if (numerator == 0) return "0";
      using LL = long long;
      string ans = "";
      LL num = numerator;
      LL de = denominator;
      bool minus = false;
      if (num < 0) {
        num = -num;
        minus = !minus;
      }
      if (de < 0) {
        de = -de;
        minus = !minus;
      }

      if (minus)
        ans += '-';

      ans += to_string(num / de); 
      num %= de;

      if (num == 0) return ans;
      ans += '.';
      unordered_map<LL, int> ma;
      while (num != 0) {
        // 注意位置
        auto p = ma.insert({num, ans.size()});
        num *= 10;
        LL d = num / de;
        num %= de;
        if (p.second) {
          ans += to_string(d);
        } else {
          ans.insert(ans.begin() + p.first->second, '(');
          ans += ')';
          break;
        }
      }
      return ans;
    }
};

int main() {
  if (1) {
  cout << Solution().fractionToDecimal(1, 2) << endl;
  cout << Solution().fractionToDecimal(2, 3) << endl;
  cout << Solution().fractionToDecimal(-2, 3) << endl;
  cout << Solution().fractionToDecimal(4, 333) << endl;
  cout << Solution().fractionToDecimal(10, 7) << endl;
  cout << Solution().fractionToDecimal(0, 6) << endl;
  }
  cout << Solution().fractionToDecimal(1, 6) << endl;
  cout << Solution().fractionToDecimal(-1, -6) << endl;
  return 0;
}
