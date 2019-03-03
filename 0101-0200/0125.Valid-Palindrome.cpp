#include "common.h"

class Solution {
public:
    bool isPalindrome(string s) {
      int i = 0;
      int j = s.size() - 1;
      while (i < j) {
        while(i < j && !isalnum(s[i])) ++i;
        while(i < j && !isalnum(s[j])) --j;
        if (i < 0 || i >= s.size()) return true;
        if (j < 0 || j >= s.size()) return true;
        if (i < j) {
          char ci = s[i];
          char cj = s[j];
          if (ci >= 'A' && ci <= 'Z') ci = ci - 'A' + 'a';
          if (cj >= 'A' && cj <= 'Z') cj = cj - 'A' + 'a';
          if (ci != cj) return false;
          ++i; --j;
        } else {
          break;
        }
      }
      return true;
    }
};

int main() {
  string s;
  cin >> s;
  Solution so;
  cout << so.isPalindrome(s) << endl;
  return 0;
}
