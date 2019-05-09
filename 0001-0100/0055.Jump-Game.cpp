#include "common.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int far = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (i <= far) {
          far = max(far, i + nums[i]);
          if (far >= nums.size() - 1) return true;
        } else {
          return false;
        }
      }
      return false;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().canJump(nums) << endl;
  return 0;
}
