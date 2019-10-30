#include "common.h"

class Solution {
public:
  string ReverseSentence(string str) {
    const int len = str.size();
    int i = 0;
    for (int j = 1; j < len; ++j) {
      if (str[j] == ' ') {
        rotate(str, i, j);
        i = j + 1;
      }
    }
    rotate(str, i, len);
    rotate(str, 0, len);
    return str;
  }
private:
  void rotate(string &s, int start, int end) {
    for (int i = start, j = end - 1; i < j; ++i, --j) {
      swap(s[i], s[j]);
    }
  }
};

int main() {
  string s;
  getline(cin, s);
  cout << Solution().ReverseSentence(s) << endl;
  return 0;
}
