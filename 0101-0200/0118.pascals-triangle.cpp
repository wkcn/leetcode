#include "common.h"

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

int main() {
  int r; cin >> r;
  auto out = Solution().generate(r);
  for (auto &v : out) {
    PRINT_ARRAY(v);
  }
  return 0;
}
