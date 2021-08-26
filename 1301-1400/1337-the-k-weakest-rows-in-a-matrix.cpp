#include "common.h"

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      vector<pair<int, int>> lens;
      int r = 0;
      for (auto &vs : mat) {
        lens.push_back({get_cnt(vs), r++});
      }
      partial_sort(lens.begin(), lens.begin() + k, lens.end());
      vector<int> ans;
      for (int i = 0; i < k; ++i) {
        ans.push_back(lens[i].second);
      }
      return ans;
    }
    int get_cnt(vector<int> &vs) {
      int lo = 0, hi = vs.size();
      while (lo < hi) {
        int mid = (lo + ((hi - lo) >> 1));
        vs[mid] ? lo = mid + 1 : hi = mid;
      }
      return lo;
    }
};

int main() {
  vector<vector<int>> mat =
          {{1,1,0,0,0},
           {1,1,1,1,0},
           {1,0,0,0,0},
           {1,1,0,0,0},
           {1,1,1,1,1}};
  int k = 3;
  PRINT_ARRAY(Solution().kWeakestRows(mat, k));
  return 0;
}
