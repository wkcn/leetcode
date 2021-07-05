#include "common.h"

class Solution {
public:
    string frequencySort(string s) {
      array<int, 256> cnts{0};
      for (char c : s) ++cnts[c];
      vector<pair<char, int>> vs;
      for (int c = 0; c <= 255; ++c) {
        if (cnts[c]) {
          vs.emplace_back(c, cnts[c]); 
        }
      }
      sort(vs.begin(), vs.end(), [](pair<char, int> &a, pair<char, int> &b) {
          return a.second > b.second;
      });
      string ans;
      for (auto &p : vs) {
        ans += string(p.second, p.first);
      }
      return ans;
    }
};

int main() {
  cout << Solution().frequencySort("tree") << endl;
  return 0;
}
