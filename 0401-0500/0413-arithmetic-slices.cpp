#include "common.h"

class Solution {
  public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int diff = nums[0] - nums[1];
    int cnt = 2;
    int ans = 0;
    auto F = [&]() {
      if (cnt < 2) return;
      // (cnt - 3 + 1) + (cnt - 4 + 1) + ... + 1
      ans += (cnt - 1) * (cnt - 2) / 2;
    };
    for (int i = 2; i < nums.size(); ++i) {
      int d = nums[i - 1] - nums[i];
      if (d == diff) ++cnt;
      else {
        diff = d;
        F();
        cnt = 2;
      }
    }
    F();
    return ans;
  }
};

int main() {
  vector<int> nums{1,2,3,4};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  return 0;
}
