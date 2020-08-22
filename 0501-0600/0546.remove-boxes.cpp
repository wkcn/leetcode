#include "common.h"

// 中间去掉后, 两侧可能连续
// 要保证策略能覆盖所有方法
int dp[101][101][101];
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        function<int(int, int, int)> F;
        // [lo, hi], k为hi后面的和boxes[hi]相等的数字个数
        F = [&](int lo, int hi, int k) {
            if (lo > hi) return 0;
            // 当lo == hi时, 只有一个数字
            int &t = dp[lo][hi][k];
            if (t) return t;
            // 删除最后一个
            int best = F(lo, hi - 1, 0) + (k + 1) * (k + 1); 
            for (int i = lo; i < hi; ++i) {
              // A (xxx) B
              if (boxes[i] == boxes[hi]) {
                best = max(best, F(lo, i, k + 1) + F(i + 1, hi - 1, 0));
              }
            }
            return t = best;
        };
        return F(0, boxes.size() - 1, 0);
    }
};

int main() {
  vector<int> boxes;
  INPUT_ARRAY(boxes);
  cout << Solution().removeBoxes(boxes) << endl;
  return 0;
}
