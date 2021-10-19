#include "common.h"

class Solution {
  using LL = long long;
  public:
    string fractionToDecimal(int numerator, int denominator) {
      LL num = LL(numerator), den = LL(denominator);
      LL d = num / den;
      string ans = to_string(d);
      LL r = num % den;
      if (r < 0) r = -r;
      if (r == 0) return ans;
      if (d == 0 && ((num ^ den) < 0)) ans = "-0";
      if (den < 0) den = -den;
      ans += '.';
      unordered_map<int, int> ma;
      while (r > 0) {
        int i = ans.size();
        auto p = ma.insert({r, i});
        if (!p.second) {
          int j = p.first->second;
          ans.insert(j, "(");
          ans += ')';
          break;
        }
        ans += (r * 10) / den + '0';
        r = (r * 10) % den;
      }
      return ans;
    }
};

int main() {
  for (auto [n, d] : vector<pair<int,int>>{{1, 2}, {2, 1}, {2, 3}, {4, 333}, {1, 5}, {-50, 8}, {7, -12}}) {
  cout << Solution().fractionToDecimal(n, d) << endl;
  }
  return 0;
}
