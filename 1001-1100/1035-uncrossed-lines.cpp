#include "common.h"

int dp[501][501];
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      // 居然是最长公共子序列..
      // 不需要一定包含nums1[i]和nums[j]
      const int n1 = nums1.size();
      const int n2 = nums2.size();
      dp[0][0] = 0;
      for (int i = 0; i < n1; ++i) {
        dp[i + 1][0] = 0;
      }
      for (int i = 0; i < n2; ++i) {
        dp[0][i + 1] = 0;
      }
      for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
          if (nums1[i] == nums2[j]) {
            // 因为max(dp[i+1][j], dp[i][j+1]) <= dp[i][j] + 1
            dp[i+1][j+1] = dp[i][j] + 1;
          } else {
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
          }
        }
      }
      return dp[n1][n2];
    }
};

int main() {
  vector<int> nums1{1, 4, 2};
  vector<int> nums2{1, 2, 4};
  cout << Solution().maxUncrossedLines(nums1, nums2) << endl;
  return 0;
}
