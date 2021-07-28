#include "common.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
      int pos = 0, neg = 0;
      int ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
          pos = neg = 0;
          continue;
        } else if (nums[i] > 0) {
          pos = pos + 1;
          if (neg > 0)
            neg = neg + 1;
        } else {
          int old_pos = pos;
          if (neg > 0) {
            pos = neg + 1;
          } else {
            // 注意这里的处理
            pos = 0;
          }
          neg = old_pos + 1;
        }
        ans = max(ans, pos);
      }
      return ans;
    }
};

int main() {
  if (0) {
    vector<int> nums{-1,-2,-3, 0, 1};
    cout << Solution().getMaxLen(nums) << endl;
  }
  if (0) {
    vector<int> nums{1,-2,-3,4};
    cout << Solution().getMaxLen(nums) << endl;
  }
  if (1) {
    vector<int> nums{1,2,3,5,-6,4,0,10};
    cout << Solution().getMaxLen(nums) << endl;
  }
  return 0;
}
