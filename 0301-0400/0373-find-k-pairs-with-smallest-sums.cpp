#include "common.h"

class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      using pii = pair<int, int>;
      auto cmp = [&](const pii &a, const pii &b) -> bool {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
      };
      priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
      q.emplace(0, 0);
      vector<vector<int>> ans;
      unordered_set<int> vis;
      vis.insert(0);
      auto try_add = [&](int a, int b) {
        if (a < nums1.size() && b < nums2.size()) {
          if (vis.insert((a << 16) | b).second) {
            q.emplace(a, b);
          }
        }
      };
      while (!q.empty() && k-- > 0) {
        auto p = q.top(); q.pop();
        ans.push_back({nums1[p.first], nums2[p.second]});
        try_add(p.first + 1, p.second);
        try_add(p.first, p.second + 1);
      }
      return ans;
    }
};

int main() {
  vector<int> nums1{1, 7, 11};
  vector<int> nums2{2, 4, 6};
  int k = 3;
  for (auto v : Solution().kSmallestPairs(nums1, nums2, k)) {
    PRINT_ARRAY(v);
  }
  return 0;
}
