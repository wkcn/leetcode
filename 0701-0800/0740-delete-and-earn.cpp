#include "common.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      array<int, 10010> cnts{0};
      for (int x : nums) ++cnts[x];
      int del = 0, nodel = 0;
      for (int i = 1; i <= 10000; ++i) {
        int tmp = max(del, nodel);
        del = nodel + cnts[i] * i;
        nodel = tmp;
      }
      return max(del, nodel);
    }
};

int main() {
  {
  vector<int> nums{3, 4, 2};
  cout << Solution().deleteAndEarn(nums) << endl;  // 6
  }

  {
  vector<int> nums{2,2,3,3,3,4};
  cout << Solution().deleteAndEarn(nums) << endl;  // 9
  }
  return 0;
}
