#include "common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> vs;
      for (int x : nums) {
        auto p = lower_bound(vs.begin(), vs.end(), x);
        if (p == vs.end()) {
          vs.push_back(x);
        } else {
          *p = x;
        }
      }
      return vs.size();
    }
};

int main() {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  cout << Solution().lengthOfLIS(nums) << endl;
  return 0;
}
