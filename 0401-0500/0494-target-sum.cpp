#include "common.h"

#define SOLUTION 4

#if SOLUTION == 1
const int M = 20000;
int dp[2][2 * M + 1];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      // sum in [-20000, 20000] -> [0, 40000]
      memset(dp[0], 0, sizeof(dp[0]));
      // 这里要+M
      dp[0][0 + M] = 1;
      int cur = 0;
      for (int x : nums) {
        int next = 1 - cur;
        for (int t = 2 * M; t >= x; --t) {
          dp[next][t] = dp[cur][t - x];
        }
        for (int t = 0; t < x; ++t) dp[next][t] = 0;
        for (int t = 0; t <= 2 * M - x; ++t) {
          dp[next][t] += dp[cur][t + x];
        }
        cur = next;
      }
      return dp[cur][target + M];
    }
};
#elif SOLUTION == 2

int dp[1501];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      // su in [0, 1000]
      // target in [-1000, 1000]
      const int su = accumulate(nums.begin(), nums.end(), 0);
      // 假设放+的数为pos, 放-的数为neg
      // 有pos + neg = su, pos - neg = target
      // 是否可以利用条件: pos - target = neg >= 0有pos >= target
      // pos - (su - pos) = target, 2 * pos = su + target
      // pos = (su + target) / 2
      // 也就是找pos为(su + target) / 2的方案数
      if ((su + target) % 2 == 1) return 0;
      // tar in [-1000, 2000] / 2 -> [-500, 1000] -> [0, 1500] - M
      const int M = 500;
      const int tar = (su + target) / 2;
      for (int t = 0; t <= tar + M; ++t) dp[t] = 0;
      dp[0 + M] = 1;
      for (int x : nums) {
        for (int t = tar + M; t >= x; --t) {
          dp[t] += dp[t - x];
        }
      }
      return dp[tar + M];
    }
};

#elif SOLUTION == 3

int dp[1001];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      const int su = accumulate(nums.begin(), nums.end(), 0);
      // neg = (su - target) / 2
      if ((su - target) % 2 == 1) return 0;
      if (su < target) return 0;
      // su >= target
      // tar in [0, 2000] / 2 -> [0, 1000]
      const int tar = (su - target) / 2;
      dp[0] = 1;
      for (int t = 1; t <= tar; ++t) dp[t] = 0;
      for (int x : nums) {
        for (int t = tar; t >= x; --t) {
          dp[t] += dp[t - x];
        }
      }
      return dp[tar];
    }
};

#elif SOLUTION == 4

int dp[1001];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      const int su = accumulate(nums.begin(), nums.end(), 0);
      // pos + neg = su, pos - neg = target
      // 2 * neg = su - target >= 0
      // diff in [-1000, 2000]
      const int diff = su - target;
      if (diff < 0) return 0; 
      if (diff % 2) return 0;
      // neg in [0, 1000]
      const int neg = diff / 2;
      // 0/1背包, 目标是和为neg
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;
      for (int x : nums) {
        for (int t = neg; t >= x; --t) {
          dp[t] += dp[t - x];
        } 
      }
      return dp[neg];
    }
};

#endif

int main() {
  vector<int> nums{1, 1, 1, 1, 1};
  int target = 3;
  cout << Solution().findTargetSumWays(nums, target) << endl;
  return 0;
}
