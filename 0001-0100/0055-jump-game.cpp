#include "common.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int ma = 0;
      for (int i = 0; i <= ma && i < nums.size(); ++i) {
        ma = max(ma, i + nums[i]); 
      }
      return ma >= int(nums.size()) - 1;
    }
};

int main() {
  {
    vector<int> nums{2, 3, 1, 1, 4};
    cout << Solution().canJump(nums) << endl;
  }

  {
    vector<int> nums{3, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
  }
  return 0;
}
