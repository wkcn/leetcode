// 每个物品的贡献是一样的
#include "common.h"

#define SOLUTION 2
#if SOLUTION == 1
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(costs.begin(), costs.end());
      int k = 0;
      for (int x : costs) {
        if (x <= coins) ++k;
        else break;
        coins -= x;
      }
      return k;
    }
};
#elif SOLUTION == 2

int cnts[100001];
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      memset(cnts, 0, sizeof(cnts));
      for (int x : costs) ++cnts[x];
      int ans = 0;
      for (int i = 1; i <= 100000; ++i) {
        if (cnts[i] > 0) {
          int y = min(cnts[i], coins / i);
          ans += y;
          coins -= y * i;
        }
      }
      return ans;
    }
};

#endif

int main() {
  vector<int> costs{1,3,2,4,1};
  int k = 7;
  cout << Solution().maxIceCream(costs, k) << endl;
  return 0;
}
