#include "common.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
      if (weights.empty()) return 0;
      const int max_weight = *max_element(weights.begin(), weights.end());
      const int sum_weight = accumulate(weights.begin(), weights.end(), 0);
      int lo = max_weight, hi = sum_weight + 1;
      // 注意上下界
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        int w = 0;
        int d = 0;
        for (int i = 0; i < weights.size() && d < D; ++i) {
          w += weights[i]; 
          if (w > mid) {
            // 注意这里假设了weights[i] <= mid
            w = weights[i];
            ++d;
          }
        }
        if (d < D) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }
      return lo;
    }
};

int main() {
  if (0) {
    vector<int> weights = {3,2,2,4,1,4};
    int D = 3;
    cout << Solution().shipWithinDays(weights, D) << endl;
  }
  vector<int> vs;
  cout << (min_element(vs.begin(), vs.end())==vs.end()) << endl;
  if (0) {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    // 15
    cout << Solution().shipWithinDays(weights, D) << endl;
  }
  {
    vector<int> weights = {1,2,3,1,1};
    int D = 4;
    cout << Solution().shipWithinDays(weights, D) << endl;
  }
  return 0;
}
