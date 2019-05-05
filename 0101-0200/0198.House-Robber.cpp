#include "common.h"

class Solution {
public:
  int rob(vector<int>& nums) {
    int l1 = 0, l2 = 0;
    // l2, l1, now >>>
    //     l2, l1
    for (int u : nums) {
      int tmp = l1;
      l1 = l2 + u;
      l2 = max(l2, tmp);
    }
    return max(l1, l2);
  }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().rob(nums) << endl;
  return 0;
}
