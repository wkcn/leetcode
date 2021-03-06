#include "common.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
          if (a[0] != b[0]) return a[0] < b[0];
          return a[1] > b[1];  // 避免同宽度连续套娃
      });
      vector<int> max_h;  // 从小到大
      for (auto &v : envelopes) {
        auto p = lower_bound(max_h.begin(), max_h.end(), v[1]);
        if (p == max_h.end()) {
          max_h.push_back(v[1]);
        } else {
          *p = v[1];
        }
      }
      return max_h.size();
    }
};

int main() {
  vector<vector<int> > envelopes = {{5,4},{6,4},{6,7},{2,3}};
  cout << Solution().maxEnvelopes(envelopes) << endl;

  vector<vector<int> > envelopes2 = {{1,1},{1,1},{1,1}};
  cout << Solution().maxEnvelopes(envelopes2) << endl;
}
