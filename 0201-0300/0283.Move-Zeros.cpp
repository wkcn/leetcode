#include "common.h"

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int z = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) nums[z++] = nums[i];
    }
    for (;z<nums.size();++z) nums[z]=0;
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  Solution().moveZeroes(nums);
  PRINT_ARRAY(nums);
  return 0;
}
