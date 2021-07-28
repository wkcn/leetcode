#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
      sort(ranges.begin(), ranges.end());
      // 按顺序消除
      for (auto &vs : ranges) {
        if (vs[0] > left) return false;
        // vs[0] <= left
        left = max(left, vs[1] + 1);
      }
      return left > right;
    }
};
#elif SOLUTION == 2

// 差分数组
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    }
};
#endif

int main() {
  vector<vector<int>> ranges{{1,2}, {3,4}, {5,6}};
  int left = 2, right = 5;
  cout << Solution().isCovered(ranges, left, right) << endl;
  return 0;
}
