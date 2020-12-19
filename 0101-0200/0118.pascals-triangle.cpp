#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int> > ans(numRows);
        for (int r = 0; r < numRows; ++r) {
            vector<int> &buf = ans[r];
            buf.push_back(1);
            for (int c = 1; c < r; ++c) {
                buf.push_back(ans[r - 1][c - 1] + ans[r - 1][c]);
            }
            if (r >= 1) buf.push_back(1);
        }
        return ans;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int r = 0; r < numRows; ++r) {
            ans[r].resize(r + 1);
            auto &vs = ans[r];
            vs.front() = vs.back() = 1;
            if (r < 2) continue;
            auto &last = ans[r - 1];
            for (int c = 1; c < r; ++c) {
                vs[c] = last[c] + last[c - 1];
            }
        }
        return ans;
    }
};
#endif

int main() {
  int r; cin >> r;
  auto out = Solution().generate(r);
  for (auto &v : out) {
    PRINT_ARRAY(v);
  }
  return 0;
}
