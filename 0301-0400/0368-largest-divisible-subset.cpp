#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 将dp[i]定义为以nums[i]结尾的最大整除子集的最大数字
        const int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
          int max_len = -1;
          int best_j;
          for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
              const int len = dp[j].size() + 1;
              if (len > max_len) {
                max_len = len;
                best_j = j;
              }
            }
          }
          if (max_len > 0) {
            dp[i] = dp[best_j];
          }
          dp[i].push_back(nums[i]);
        }
        int max_len = 0, best_i;
        for (int i = 0; i < n; ++i) {
          const int len = dp[i].size();
          // dp[i].size()类型是无符号整数!!!!!
          if (len > max_len) {
            best_i = i;
            max_len = len;
          }
        }
        return dp[best_i];
    }
};
#elif SOLUTION == 2

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 将dp[i]定义为以nums[i]结尾的最大整除子集的最大数字
        // 无后效性
        const int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
              dp[i] = max(dp[i], dp[j] + 1);
            }
          }
        }
        auto max_len_p = max_element(dp.begin(), dp.end());
        int len = *max_len_p;
        int max_len_i = max_len_p - dp.begin();
        int j = max_len_i;
        vector<int> ans;
        for (int i = max_len_i; i >= 0; --i) {
          if (dp[i] == len && nums[j] % nums[i] == 0) {
            ans.push_back(nums[i]);
            --len;
            j = i;
          }
        }
        return ans;
    }
};

#endif

int main() {
  {
    vector<int> nums{1, 2, 3};
    PRINT_ARRAY(Solution().largestDivisibleSubset(nums));
  }
  {
    vector<int> nums{1, 2, 4, 8};
    PRINT_ARRAY(Solution().largestDivisibleSubset(nums));
  }
  return 0;
}
