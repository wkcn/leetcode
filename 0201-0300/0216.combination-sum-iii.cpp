#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> out;
        vector<int> buf;
        function<void(int start, int rest)> F = [&](int start, int rest) {
          if (rest == 0 && buf.size() == k) {
            out.push_back(buf);
            return;
          }
          if (start > 9) return;
          if (start > rest) return;
          F(start + 1, rest);
          if (buf.size() < k) {
            buf.push_back(start);
            F(start + 1, rest - start);
            buf.pop_back();
          }
        };
        F(1, n);
        return out;
    }
};

int main() {
  int k, n;
  cin >> k >> n;
  for (auto v : Solution().combinationSum3(k, n)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
