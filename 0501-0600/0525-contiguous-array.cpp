#include "common.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int pre = 0;
      int ans = 0;
      unordered_map<int, int> ma;
      ma[0] = -1;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) pre -= 1;
        else pre += 1;
        auto p = ma.insert({pre, i});
        if (!p.second) {
          ans = max(ans, i - p.first->second);
        }
      }
      return ans;
    }
};

int main() {
  vector<int> nums{0, 1, 0};
  cout << Solution().findMaxLength(nums) << endl;
  return 0;
}
