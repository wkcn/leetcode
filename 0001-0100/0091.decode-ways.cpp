#include "common.h"

// 0不可以单独作为1位
// 0若是原码的一部分，那么它前面必须是1或2
class Solution {
public:
    int numDecodings(string s) {
        const int len = s.size();
        if (len == 0 || s[0] == '0') return 0;
        int last = 1;
        int cur = 1;
        for (int i = 1; i < len; ++i) {
            int old_last = last;
            last = cur;
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] >= '3')) return 0;
            if (s[i - 1] == '1' || (s[i] <= '6' && s[i - 1] == '2')) {
              if (s[i] == '0') cur = old_last;
              else cur = cur + old_last;
            } else {
            }
        }
        return cur;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().numDecodings(s) << endl;
  return 0;
}
