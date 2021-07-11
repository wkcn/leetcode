#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
      int presum = 0;
      int ans = nums[0];
      int i = 0;
      for (int T = 0; T < 2; ++T) {
        for (int x : nums) {
          // index is i
          presum += x;
          // 注意第二个条件不包括等于
          while (!q.empty() && i - q.top().second > nums.size()) {
            q.pop();
          }
          if (!q.empty()) ans = max(ans, presum - q.top().first);
          q.push({presum, i});
          ++i;
        }
      }
      return ans;
    }
};
#elif SOLUTION == 2

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    /*
     * 记录dp[j]为以nums[j]结尾的最大连续子数组和
     * dp[j] = max_i(nums[i] + nums[i + 1] + ... + nums[j])
     *
     * 要么和前面连续, 要么不连续(0)
     * dp[j+1] = max_i(nums[i] + nums[i + 1] + ... + nums[j+1])
     *         = max(dp[j], 0) + nums[j + 1]
     */
    // 先算不循环的情况
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], 0) + nums[i];
      ans = max(ans, dp[i]);
    }
    vector<int> maxright(nums.size());
    maxright.back() = nums.back();
    int su = nums.back();
    for (int i = int(nums.size()) - 2; i >= 0; --i) {
      su += nums[i];
      maxright[i] = max(maxright[i + 1], su);
    }
    su = 0;
    for (int i = 0; i < int(nums.size()) - 2; ++i) {
      su += nums[i];
      ans = max(ans, su + maxright[i + 2]); 
    } 
    // 考虑循环
    return ans;
  }
};
#endif

int main() {
  if (0) {
  vector<int> nums{1,-2,3,-2};
  cout << Solution().maxSubarraySumCircular(nums) << endl;
  }
  {
  vector<int> nums{5,-3,5};
  cout << Solution().maxSubarraySumCircular(nums) << endl;
  }
  if (0) {
  vector<int> nums{3,1,3,2,6};
  cout << Solution().maxSubarraySumCircular(nums) << endl;
  }
  return 0;
}
