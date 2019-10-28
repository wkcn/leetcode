#include "common.h"

class Solution {
public:
  int FirstNotRepeatingChar(string str) {
    vector<int> rec(256, 0);
    for (char c : str) {
      ++rec[c];
    }
    for (int i = 0; i < str.size(); ++i) {
      if (rec[str[i]] == 1) return i;
    }
    return -1;
  }
};

int main() {
  string str;
  cin >> str;
  cout << Solution().FirstNotRepeatingChar(str) << endl;
  return 0;
}
