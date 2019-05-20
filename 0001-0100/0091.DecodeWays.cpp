#include "common.h"

class Solution {
public:
    int numDecodings(string s) {
      if (s.empty()) return 0;
      if (s[0] == '0') return 0;
      int last2 = 1;
      int last1 = 1;
      char last_c = s[0];
      for (int i = 1; i < s.size(); ++i) {
        char &c = s[i];
        int now = 0;
        if (last_c == '1' || (last_c == '2' && c <='6')) {
          now += last2;
        }
        // single
        if (c > '0') now += last1;
        else if (last_c >= '3') return 0;

        last2 = last1;
        last1 = now;
        last_c = c;
      }
      return last1;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().numDecodings(s) << endl;
  return 0;
}
