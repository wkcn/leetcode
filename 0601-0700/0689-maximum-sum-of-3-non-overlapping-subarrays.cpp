#include "common.h"

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> presum(n + 1); presum[0] = 0;
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + nums[i];
    }
    vector<vector<int>> dp(4, vector<int>(n + 1));
    vector<vector<int>> idx(4, vector<int>(n + 1));
    // init
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int t = 0; t < 3; ++t) {
      int max_value = INT32_MIN;
      int best_idx = -1;
      for (int i = n - k * (t + 1); i >= 0; --i) {
        int s = presum[i + k] - presum[i];
        s += dp[t][i + k];
        if (s >= max_value) {
          best_idx = i;
          max_value = s;
        }
        dp[t + 1][i] = max_value;
        idx[t + 1][i] = best_idx;
      }
    }
    vector<int> ans(3);
    int e = 0;
    for (int t = 2; t >= 0; --t) {
      e = idx[t + 1][e];
      ans[2 - t] = e;
      e += k;
    }
    return ans;
  }
};

int main() {
  {
  vector<int> nums{1,2,1,2,6,7,5,1};
  int k = 2;
  PRINT_ARRAY(Solution().maxSumOfThreeSubarrays(nums, k));
  }
  {
  vector<int> nums{1,2,1,2,1,2,1,2,1};
  int k = 2;
  PRINT_ARRAY(Solution().maxSumOfThreeSubarrays(nums, k));
  }
  return 0;
}
