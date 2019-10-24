#include "common.h"

class Solution {
public:
  vector<string> Permutation(string str) {
    if (str.empty()) return {};
    const int len = str.size();
    char* ptr = &str[0];
    vector<string> res;
    sort(str.begin(), str.end());
    res.push_back(str);
    int i;
    while (1) {
      for (i = len-1; i > 0; --i) {
        if (str[i] > str[i-1]) break;
      }
      if (i == 0) break;
      char *p = lower_bound(ptr + i, ptr + len, str[i-1], greater<char>())-1; 
      swap(*p, str[i-1]);
      reverse(ptr+i, ptr+len);
      res.push_back(str);
    }
    return res;
  }
};

int main() {
  string str;
  cin >> str;
  vector<string> vs = Solution().Permutation(str);
  for (string s : vs) {
    cout << s << endl;
  }
  return 0;
}
