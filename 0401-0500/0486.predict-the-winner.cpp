#include "common.h"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();
        // dp[i, j]表示区间[i, j]回合, 先手玩家的分数 - 后手玩家的分数
        vector<int> dp = nums;
        // dp[i, j], i <= j, 闭区间
        // len = j - i + 1
        // 当len = 1, 即i == j时, dp[i, j] = nums[i];
        // 当len = 2, dp[i, j] = max({nums[i], nums[j]}) - min({nums[i], nums[j]});
        // 当len > 2时, dp[i, j] = max(nums[i] - dp[i+1, j], nums[j] - dp[i, j-1]); // 可以与len = 2的情况合并
        for (int e = 1; e < N; ++e) {
            for (int i = 0, j = e; j < N; ++i, ++j) {
                dp[i] = max(nums[i] - dp[i+1], nums[j] - dp[j-e]); // 注意后面的dp项
            }
        }
        return dp[0] >= 0;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().PredictTheWinner(nums) << endl;
  return 0;
}
