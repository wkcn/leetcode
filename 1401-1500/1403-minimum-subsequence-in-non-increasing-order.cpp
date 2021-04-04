#include "common.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      sort(nums.begin(), nums.end(), greater<int>());
      int su = accumulate(nums.begin(), nums.end(), 0);
      int half = su / 2;
      int h = 0;
      for (int i = 0; i < nums.size(); ++i) {
        h += nums[i];
        if (h > half) {
          nums.resize(i + 1);
          return nums;
        }
      }
      return nums;
    }
};

int main() {
  vector<int> nums{4, 3, 10, 9, 8};
  PRINT_ARRAY(Solution().minSubsequence(nums));
  return 0;
}
