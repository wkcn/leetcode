#include "common.h"

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      const int size = row.size();
      if (size <= 0) return 0;
      const int m = size / 2;
      vector<vector<int> > pos(m);
      for (int i = 0; i < size; ++i) {
        pos[row[i] / 2].push_back(i/2);
      }
      vector<vector<int> > connect(m);
      for (vector<int> &p : pos) {
        // p[0] <-> p[1]
        connect[p[0]].push_back(p[1]);
        connect[p[1]].push_back(p[0]);
      }
      int cycle = 0;
      for (int i = 0; i < m; ++i) {
        if (connect[i].empty()) continue;
        int cur = i;
        do {
          int next = connect[cur].back(); connect[cur].pop_back();
          vector<int> &v = connect[next];
          v.erase(find(v.begin(), v.end(), cur));
          cur = next;
        } while (cur != i);
        ++cycle;
      }
      return m - cycle;
    }
};


int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().minSwapsCouples(nums) << endl;
  return 0;
}
