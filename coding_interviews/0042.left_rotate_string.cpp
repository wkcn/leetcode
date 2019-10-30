#include "common.h"

#if 0
class Solution {
public:
    string LeftRotateString(string str, int n) {
      if (str.empty()) return {};
      n %= str.size();
      string left = str.substr(0, n);
      string right = str.substr(n, str.size() - n);
      return right + left;
    }
};
#else

// YX = (X^T Y^T)^T
class Solution {
public:
  string LeftRotateString(string str, int n) {
    const int len = str.size();
    if (len <= 0) return {};
    n %= len;
    rotate(str, 0, n);
    rotate(str, n, len);
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

#endif

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  cout << Solution().LeftRotateString(s, n) << endl;
  return 0;
}
