#include "common.h"

class Solution {
public:
    vector<string> permutation(string s) {
      if (s.empty()) return {};
      sort(s.begin(), s.end());
      vector<string> ans; ans.push_back(s);
      while (1) {
        int i;
        for (i = (int)s.size() - 2; i >= 0 && s[i] >= s[i + 1]; --i);
        // s[i] < s[i + 1]
        if (i == -1) break;
        auto p = upper_bound(s.rbegin(), s.rbegin() + (s.size() - (i + 1)), s[i]);
        swap(s[i], *p);
        reverse(s.begin() + i + 1, s.end()); 
        ans.push_back(s);
      }
      return ans;
    }
};

int main() {
  auto vs = Solution().permutation("abb");
  for (string s : vs) {
    cout << s << endl;
  }
  return 0;
}
