#include "common.h"

struct hasher {
  const int MOD = int(1e5) + 7;
  size_t operator()(const array<int, 26> &data) const {
    int v = 0;
    for (int i = 0; i < 26; ++i) {
      v = (v * 1007 + data[i]) % MOD;
    }
    return v;
  }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<array<int, 26>, vector<string>, hasher> ma;
      for (string &s : strs) {
        array<int, 26> cnts{0};
        for (char c : s) {
          ++cnts[c - 'a'];
        }
        ma[cnts].push_back(s);
      }
      vector<vector<string>> ans;
      for (auto &[k, v] : ma) {
        ans.emplace_back(move(v));
      }
      return ans;
    }
};

int main() {
  cout << sizeof(size_t) << ", " << sizeof(int) << endl;
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  PRINT_ARRAY2D(Solution().groupAnagrams(strs));
  return 0;
}
