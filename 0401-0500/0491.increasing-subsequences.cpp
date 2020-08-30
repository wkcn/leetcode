// TODO: 递归解法
#include "common.h"


class Solution {
public:
    const int MOD = (1e9)+7;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      const int N = nums.size();
      const int BASE = 263;
      unordered_set<int> vis;
      vector<vector<int> > res;
      for (int i = 1; i < (1 << N); ++i) {
        if ((i & (i - 1)) == 0) continue;
        vector<int> seq;
        int m = i;
        int h = 0;
        bool fail = false;
        for (int t = 0; t < N; ++t) {
          if (m & 1) {
            const int v = nums[t];
            // 应该这样累加算!, 为什么+100过不了, +101就过了???
            // 原因是假如不放数字也是0, 那么放数字时应该大于0
            // 注意这里的数字变成了longlong!!!
            h = (static_cast<long long>(h) * BASE + (v + 101)) % MOD;
            if (!seq.empty() && seq.back() > v) {
              fail = true;
              break;
            }
            seq.push_back(v);
          }
          m >>= 1;
        }
        if (!fail) {
          if (vis.insert(h).second) {
            res.emplace_back(std::move(seq));
          }
        }
      }
      return res;
    }
};


int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  auto m = (Solution().findSubsequences(nums));
  PRINT_ARRAY2D(m);
  return 0;
}
