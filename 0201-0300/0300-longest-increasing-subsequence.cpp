#include "common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> rec;
      for (int x : nums) {
        // 等于的时候不更新
        auto p = lower_bound(rec.begin(), rec.end(), x);
        if (p == rec.end()) rec.push_back(x);
        else *p = x; // 此时的*p >= x
      }
      return rec.size();
    }
};

int main() {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  cout << Solution().lengthOfLIS(nums) << endl;
  return 0;
}
