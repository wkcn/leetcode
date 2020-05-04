// TODO: 理解清其他解法，比如双指针，前缀和
#include "common.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      const int n = nums.size();
      if (n <= 0) return 0;
      int ans = 0;
      vector<int> cnts(n + 1, 0);
      int odd = 0;
      cnts[0] = 1; // 初始化！
      for (int i = 0; i < n; ++i) {
        odd += nums[i] & 1;
        ans += odd >= k ? cnts[odd - k] : 0;
        ++cnts[odd];
      }
      return ans;
    }
};

int main() {
  vector<int> nums;
  int k;
  INPUT_ARRAY(nums);
  cin >> k;
  cout << Solution().numberOfSubarrays(nums, k) << endl;
  return 0;
}
