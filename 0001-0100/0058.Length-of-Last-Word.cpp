#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
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
#elif SOLUTION == 2

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') --i;
        int j = i;
        while (j >= 0 && s[j] != ' ') --j;
        return i - j;
    }
};

#endif

int main() {
  string s;
  cin >> s;
  cout << Solution().lengthOfLastWord(s) << endl;
  return 0;
}
