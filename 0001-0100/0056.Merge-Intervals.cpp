#include "common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.empty()) return {};
      sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
          if (a[0] < b[0]) return true;
          if (a[0] == b[0]) return a[1] < b[1];
          return false;
      });
      vector<vector<int>> ans;
      vector<int> now_iv = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        vector<int> &sel_iv = intervals[i];
        if (now_iv[1] < sel_iv[0]) {
          ans.push_back(now_iv);
          now_iv = std::move(sel_iv);
        } else {
          // now_iv[1] >= sel_iv[0]
          if (sel_iv[1] <= now_iv[1]) {
            // include
            continue;
          } else {
            now_iv[1] = sel_iv[1];
          }
        }
      }
      ans.emplace_back(std::move(now_iv));
      return ans;
    }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int> > vs;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    vs.push_back({a, b});
  }
  auto res = Solution().merge(vs);
  bool first = true;
  for (auto &p : res) {
    if (first) first = false;
    else cout << ", ";
    cout << "[" << p[0] << ", " << p[1] << "]";
  }
  cout << endl;
  return 0;
}
