#include "common.h"

constexpr int M = 1 << 10;
int dp[2][M];
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
      // 使得长度为k的区间异或结果为0
      // a[i] ^ ... ^ a[i + k - 1] = 0
      // a[i + 1] ^ ... ^ a[i + k] = 0
      // so, a[i] ^ a[i + k] = 0 => a[i] = a[i + k]
      // T = k
      // dp[i][mask] 指的是处理了i组, 并且异或结果为mask的更改元素次数
      // dp[i][mask] = min(dp[i - 1][mask ^ x] + g(i, x)), g(i, x)表示i组换成x的成本
      fill(dp[0], dp[0] + M, INT32_MAX);
      dp[0][0] = 0;
      int cur = 1;
      for (int t = 0; t < k; ++t) {
        unordered_map<int, int> cnts;
        int num = 0;
        for (int i = t; i < nums.size(); i += k) {
          ++cnts[nums[i]];
          ++num;
        }
        // set dp[cur]
        const int min_v = *min_element(dp[1-cur], dp[1-cur]+M);
        for (int mask = 0; mask < M; ++mask) {
          // x not in cnts, g(i, x) is constant
          dp[cur][mask] = min_v;
          // x in cnts
          for (auto [x, cnt] : cnts) {
            dp[cur][mask] = min(dp[cur][mask], dp[1-cur][mask ^ x] - cnt);
          }
          dp[cur][mask] += num;
        }
        cur = 1 - cur;
      }
      // 注意这里的index: 1-cur
      return dp[1 - cur][0];
    }
};

int main() {
  {
    vector<int> nums{1, 2, 0, 3, 0};
    int k = 1;
    cout << Solution().minChanges(nums, k) << endl;
  }
  return 0;
}
