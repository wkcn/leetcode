#include "common.h"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    const int n = nums.size();
    vector<unordered_map<long long, int>> dp(n);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        // j, i
        long long diff = (long long)nums[j] - nums[i];
        int cnt = dp[j][diff];
        ans += cnt;
        dp[i][diff] += cnt + 1;
      }
    }
    return ans;
  }
};

int main() {
  {
  vector<int> nums{2,4,6,8,10};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  }

  {
  vector<int> nums{7,7,7,7,7};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  }
  return 0;
}
