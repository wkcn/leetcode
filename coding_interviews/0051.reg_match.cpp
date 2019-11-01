#include "common.h"

class Solution {
public:
#if 0
  bool match(char* str, char* pattern) {
    const int len_s = strlen(str);
    const int len_p = strlen(pattern);
    vector<vector<bool> > ma(len_s + 1, vector<bool>(len_p + 1, false));
    ma[0][0] = true;
    for (int j = 1; j < len_p; j += 2) {
      if (pattern[j] == '*') ma[0][j + 1] = true;
      else break;
    }
    // ma[i][j]代表str[:i]与pattern[:j]匹配
    for (int i = 0; i < len_s; ++i) {
      char c = str[i];
      for (int j = 0; j < len_p; ++j) {
        if (pattern[j] == '*') {
          ma[i + 1][j + 1] = j > 0 && (ma[i + 1][j - 1] || ((pattern[j-1] == '.' || c == pattern[j - 1]) && (ma[i][j - 1] || ma[i][j+1])));
        } else {
          // 字母或.
          ma[i + 1][j + 1] = (pattern[j] == '.' || c == pattern[j]) && ma[i][j];
        }
      }
    }
    return ma[len_s][len_p];
  }
#else
  bool match(char* str, char* pattern) {
    const int len_s = strlen(str);
    const int len_p = strlen(pattern);
    vector<vector<bool> > ma(len_s + 1, vector<bool>(len_p + 1, false));
    ma[len_s][len_p] = true;
    for (int i = len_p - 1; i >= 0; i -= 2) {
      if (pattern[i] == '*') {
        // 一定要弄清楚，*的标记下标是哪里！
        ma[len_s][i-1] = true;
      } else break;
    }
    for (int i = len_s - 1; i >= 0; --i) {
      const char &c = str[i];
      for (int j = len_p - 1; j >= 0; --j) {
        const char &p = pattern[j];
        ma[i][j] = ((c == p || p == '.') && (ma[i+1][j+1] || (j + 1 < len_p && pattern[j+1] == '*' && (ma[i+1][j+2] || ma[i+1][j])))) || (j + 1 < len_p && pattern[j+1] == '*' && ma[i][j+2]);
      }
    }
    return ma[0][0];
  }
#endif
  bool isMatch(string s, string p) {
    return match(const_cast<char*>(s.c_str()), const_cast<char*>(p.c_str()));
  }
};

int main() {
  Solution so;
  cout << so.match("aaa", "a.a") << endl;
  cout << so.match("aaa", "ab*ac*a") << endl;
  cout << so.match("aaa", "aa.a") << endl;
  cout << so.match("aaa", "ab*a") << endl;
  cout << so.match("a", "ab*") << endl;
  return 0;
}
