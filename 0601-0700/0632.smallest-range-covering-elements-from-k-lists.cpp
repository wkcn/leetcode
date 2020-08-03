// TODO: Hash的方法
#include "common.h"

// 优先队列可以存index
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      const int k = nums.size();
      vector<int> inds(k, 0);
      auto cmp = [&](const int ai, const int bi) {
        return nums[ai][inds[ai]] > nums[bi][inds[bi]];
      };
      priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
      int maxv = nums[0][0];
      for (int i = 0; i < k; ++i) {
        q.push(i);
        maxv = max(maxv, nums[i][0]);
      }
      int start = 0;
      int len = INT32_MAX;
      while (!q.empty()) {
        int i = q.top(); q.pop();
        int left = nums[i][inds[i]];
        int l = maxv - left;
        if (l < len) {
          len = l;
          start = left;
        }
        if (++inds[i] >= nums[i].size()) break;
        maxv = max(maxv, nums[i][inds[i]]);
        q.push(i);
      }
      return {start, start + len};
    }
};

int main() {
  int k; cin >> k;
  vector<vector<int> > nums(k);
  for (int i = 0; i < k; ++i) {
    INPUT_ARRAY(nums[i]);
  }
  PRINT_ARRAY(Solution().smallestRange(nums));
  return 0;
}
