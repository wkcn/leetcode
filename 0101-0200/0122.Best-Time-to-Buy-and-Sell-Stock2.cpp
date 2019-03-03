#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      const int n = prices.size();
      int res = 0;
      for (int i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) res += prices[i+1] - prices[i];
      }
      return res;
    }
};

int main() {
  vector<int> prices;
  INPUT_ARRAY(prices);
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
