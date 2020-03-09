// 最长上升子序列 [HARD]
#include "common.h"

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
      if (box.empty()) return 0;
      // 宽 wi、高hi、深di
      sort(box.begin(), box.end(), [](const vector<int> & a, const vector<int> & b) {
          if (a[0] != b[0]) return a[0] < b[0];
          if (a[1] != b[1]) return a[1] > b[1];
          return a[2] > b[2];
      });
      const int len = box.size();
      vector<int> dp(len, 0);
      dp[0] = box[0][2];
      for (int i = 1; i < len; ++i) {
        int width = box[i][0];
        int depth = box[i][1];
        int height = box[i][2];
        int max_val = 0;
        for (int j = 0; j < i; ++j) {
          // width > box[j][0] 的条件可以去掉，因为经过排序，有box[j][0] <= width 
          // 当box[j][0] == width时，box[j][1] >= depth, 和条件depth > box[j][1]刚好相反
          if (width > box[j][0] && depth > box[j][1] && height > box[j][2]) {
            if (dp[j] > max_val) max_val = dp[j];
          }
        }
        dp[i] = max_val + height;
      }
      int best = 0;
      for (int v : dp) if (v > best) best = v;
      return best;
    }
};

int main() {
  vector<vector<int>> box;
  INPUT_ARRAY2D(box);
  cout << Solution().pileBox(box) << endl;
  return 0;
}
