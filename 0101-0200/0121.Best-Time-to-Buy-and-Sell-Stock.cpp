#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      const int n = prices.size();
      if (n <= 1) return 0;
      int lo = prices[0];
      int best = 0;
      for (int i = 1; i < n; ++i) {
        const int &v = prices[i];
        if (v < lo) lo = v;
        else if (v - lo > best) best = v - lo;
      }
      return best;
    }
};

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
