#include "common.h"

#define SOLUTION 4

#if SOLUTION == 1
class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    const int n = nums.size();
    int ma = 0; for (int x : nums) ma |= x;
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
      int y = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j))
          y |= nums[j];
      }
      if (y == ma) ++ans;
    }
    return ans;
  }
};
#elif SOLUTION == 2

class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int ma = 0;
    function<void(int, int)> F = [&](int i, int s) {
      if (i == n) {
        if (s > ma) {
          ma = s;
          ans = 1;
        } else if (s == ma) ++ans;
        return;
      }
      F(i + 1, s | nums[i]);
      F(i + 1, s);
    };
    F(0, 0);
    return ans;
  }
};

#elif SOLUTION == 3

class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int ma = 0; for (int x : nums) ma |= x;
    vector<int> dp(ma + 1);
    dp[0] = 1;
    for (int x : nums) {
      // i == ma时，可以记录 3 | 1 = 3
      for (int i = ma; i >= 0; --i) {
        if (dp[i] > 0) {
          dp[i | x] += dp[i];
        }
      }
    }
    return dp[ma];
  }
};

#elif SOLUTION == 4

#endif

int main() {
  vector<int> nums{3, 1};
  cout << Solution().countMaxOrSubsets(nums) << endl;
  return 0;
}
