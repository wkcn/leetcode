#include "common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0) return "";
      string prefix;
      for (int i = 0; ;prefix += strs[0][i++]) {
        for (int j = 0; j < strs.size(); ++j) {
          if (i >= strs[j].size() || (j > 0 && strs[j][i] != strs[j - 1][i])) {
            return prefix;
          }
        }
      } 
      return prefix;
    }
};

int main() {
  Solution so;
  vector<string> s = {"flower", "flow", "flight"};
  // vector<string> s = {"", "b"};
  cout << so.longestCommonPrefix(s) << endl;
  return 0;
}
