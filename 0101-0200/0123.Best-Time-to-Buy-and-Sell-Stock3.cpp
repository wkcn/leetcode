#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() < 2) return 0;
      const int n = prices.size();
      vector<int> forward(n);
      vector<int> backward(n);
      int tmp = prices[0];
      int best = 0;

      forward[0] = 0;
      for (int i = 1; i < n; ++i) {
        if (prices[i] <= tmp) tmp = prices[i];
        else if (prices[i] - tmp > best) {
          best = prices[i] - tmp; 
        }
        forward[i] = best;
      }

      // backward
      backward[n - 1] = 0;
      tmp = prices.back();
      best = 0;
      for (int i = n - 2; i >= 0; --i) {
        if (prices[i] >= tmp) tmp = prices[i];
        else if (tmp - prices[i] > best) best = tmp - prices[i];
        backward[i] = best;
      }
      
      int res = max(forward.back(), backward.front());
      for (int i = 1; i < n - 1; ++i) {
        int tot = forward[i] + backward[i + 1];
        if (tot > res) res = tot;
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
