#include "common.h"

class Solution {
public:
  int lengthOfLastWord(string s) {
    int res = 0;
    int co = 0;
    for (char &c : s) {
      if (c == ' ') {
        if (co > 0) res = co;
        co = 0;
      } else ++co;
    }
    if (co > 0) res = co;
    return res;
  }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().lengthOfLastWord(s) << endl;
  return 0;
}
