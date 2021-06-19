#include "common.h"

bool used[1501];
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      // 化为0/1背包问题, +-符号
      // 分成两堆, pos和neg
      // pos + neg = su, 令pos - neg最小
      const int su = accumulate(stones.begin(), stones.end(), 0);
      const int half = su / 2;
      memset(used, 0, sizeof(used));
      used[0] = true;
      for (int x : stones) {
        for (int i = half; i >= x; --i) {
          used[i] |= used[i - x];
        }
      }
      for (int i = half; i >= 0; --i) {
        if (used[i]) return (su - i) - i;
      }
      return -1;
    }
};

int main() {
  {
    vector<int> stones{2, 7, 4, 1, 8, 1};
    cout << Solution().lastStoneWeightII(stones) << endl;
  }
  {
    vector<int> stones{31, 26, 33, 21, 40};
    cout << Solution().lastStoneWeightII(stones) << endl;
  }
  return 0;
}
