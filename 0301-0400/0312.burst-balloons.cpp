// 好题目
#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
// 从结尾推到开始
class Solution {
public:
    int maxCoins(vector<int>& nums) {
      vector<int> balls(nums.size() + 2);
      balls[0] = balls.back() = 1;
      for (int i = 0; i < nums.size(); ++i) {
        balls[i + 1] = nums[i];
      }
      // 填气球
      function<int(int, int)> F;
      map<pair<int, int>, int> ma;
      F = [&](int begin, int end) {
        // [begin, end]
        if (begin >= end) return 0;
        auto p = ma.find({begin, end});
        if (p != ma.end()) return p->second;
        int best = 0;
        for (int i = begin + 1; i < end; ++i) {
          // 理清楚下标，谁指谁
          int score = balls[begin] * balls[i] * balls[end];
          best = max(best, score + F(begin, i) + F(i, end));
        }
        return ma[{begin, end}] = best;
      };
      return F(0, balls.size() - 1);
    }
};
#elif SOLUTION == 2

// TODO: DP

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().maxCoins(nums) << endl;
  return 0;
}
