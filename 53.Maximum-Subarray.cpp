#include "common.h"

// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int best = nums[0];
      int before = best;
      for (int i = 1; i < nums.size(); ++i) {
        before = max(before + nums[i], nums[i]);
        if (before > best) best = before;
      }
      return best;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().maxSubArray(nums) << endl;
  return 0;
}
