#include "common.h"

class Solution {
public:
    string toLowerCase(string str) {
      for (int i = 0;i < str.size();++i) {
        char &c = str[i];
        if (c >= 'A' && c <= 'Z') {
          str[i] = c - 'A' + 'a';
        }
      }
      return str;
    }
};

int main() {
  Solution so;
  string s;
  cin >> s;
  cout << so.toLowerCase(s) << endl;
  return 0;
}
