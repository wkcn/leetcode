#include "common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, int> ma;
        vector<vector<string>> ans;
        for (string &s : strs) {
            array<int, 26> cnt{};
            for (char &c : s) {
                ++cnt[c - 'a'];
            }
            if (ma.find(cnt) == ma.end()) {
                ma[cnt] = ans.size();
                ans.push_back(vector<string>{s});
            } else {
                ans[ma[cnt]].push_back(s);
            }
        }
        return ans;
    }
};

int main() {
  vector<string> vs; 
  INPUT_ARRAY(vs);
  auto ans = Solution().groupAnagrams(vs);
  for (auto v : ans) {
    PRINT_ARRAY(v);
  }
  return 0;
}
