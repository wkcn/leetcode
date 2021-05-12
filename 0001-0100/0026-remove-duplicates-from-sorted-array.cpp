#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.empty()) return 0;
      int i = 0, j = 1;
      while (j < nums.size()) {
        if (nums[i] == nums[j]) ++j;
        else {
          nums[++i] = nums[j++];
        }
      }
      return i + 1;
    }
};

int main() {
  vector<int> nums{1, 1, 2};
  cout << Solution().removeDuplicates(nums) << endl;
  PRINT_ARRAY(nums);
  return 0;
}
