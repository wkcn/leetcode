#include "common.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      if (nums.size() < 3) return 0;
      int ans = 0;
      int diff = nums[1] - nums[0];
      int cnt = 2;
      auto F = [&](int n) {
        // C(n, 2) - (n - 1) = n * (n-1) / 2 - (n - 1)
        ans += n * (n - 1) / 2 - (n - 1);
      };
      for (int i = 2; i < nums.size(); ++i) {
        int d = nums[i] - nums[i - 1];
        if (d == diff) ++cnt;
        else {
          F(cnt);
          cnt = 2;
          diff = d;
        }
      }
      F(cnt);
      return ans;
    }
};

int main() {
  vector<int> nums{1,2,3,4};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  return 0;
}
