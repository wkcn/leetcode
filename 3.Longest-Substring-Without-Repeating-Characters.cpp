#include "common.h"

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> pos;
      int best = 0;
      int substr_l = 0;
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (pos.count(c)) {
          substr_l = max(substr_l, pos[c] + 1);
        }
        pos[c] = i;
        int now_len = i - substr_l + 1;
        if (now_len > best) best = now_len;
      }
      return best;
    }
};

int main() {
  Solution so;
  string s;
  while (1) {
    cin >> s; 
    cout << so.lengthOfLongestSubstring(s) << endl;
  }
  return 0;
}
