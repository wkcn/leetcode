#include "common.h"

class Solution {
public:
    int jump(vector<int>& nums) {
      int j = 1;
      vector<int> dp(nums.size());
      dp[0] = 0;
      for (int i = 0; i < nums.size(); ++i) {
        // [i + 1, i + nums[i]]
        const int right = min(i + nums[i], int(nums.size()) - 1);
        const int step = dp[i] + 1;
        while (j <= right) {
          dp[j++] = step;
        }
      }
      return dp.back();
    }
};

int main() {
  {
    vector<int> nums{2, 3, 1, 1, 4};
    cout << Solution().jump(nums) << endl;
  }
  {
    vector<int> nums{2, 3, 0, 1, 4};
    cout << Solution().jump(nums) << endl;
  }
  return 0;
}
