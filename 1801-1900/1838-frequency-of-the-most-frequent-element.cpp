#include "common.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
      if (nums.empty()) return 0;
      sort(nums.begin(), nums.end());
      int ans = 1;
      int use = 0;
      int n = 1;
      for (int i = 1; i < nums.size(); ++i) {
        // all to nums[i]
        while (1) {
          int diff = nums[i] - nums[i - 1];
          // 避免溢出
          if (diff == 0 || (k - use) / diff >= n) {
            use = use + diff * n;
            ans = max(ans, ++n);
            break;
          }
          use -= nums[i - 1] - nums[i - n];
          --n;
        }
      }
      return ans;
    }
};

int main() {
  {
  vector<int> nums{1,2,4}; int k = 5;
  cout << Solution().maxFrequency(nums, k) << endl;
  }
  {
  vector<int> nums{1,4,8,13}; int k = 5;
  cout << Solution().maxFrequency(nums, k) << endl;
  }
  return 0;
}
