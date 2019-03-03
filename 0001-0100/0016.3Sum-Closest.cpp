#include "common.h"

/*
 * Runtime: 8 ms, faster than 100.00% of C++ online submissions for 3Sum Closest.
   Memory Usage: 9.8 MB, less than 5.01% of C++ online submissions for 3Sum Closest.
 */

// reference: 15.3Sum
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      if (nums.size() < 3) return {};
      sort(nums.begin(), nums.end());

      vector<int> forward(nums.size());
      vector<int> backward(nums.size());
      // forward
      int i, j, v;
      for (i = 1, j = 0, v = nums[0]; i < nums.size(); ++i) {
        if (v != nums[i]) {
          for (int z = j; z < i; ++z) forward[z] = i;
          v = nums[i];
          j = i;
        }
      }
      for (int z = j; z < i; ++z) forward[z] = i;

      // backward
      for (i = nums.size() - 2, j = nums.size()-1, v = nums.back(); i >= 0; --i) {
        if (v != nums[i]) {
          for (int z = i + 1; z <= j; ++z) backward[z] = i;
          v = nums[i];
          j = i;
        }
      }
      for (int z = i + 1; z <= j; ++z) backward[z] = i;


      int abs_best = INT32_MAX;
      int best;
      for (int i = 0; i < nums.size() - 2; i = forward[i]) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          int su = nums[i] + nums[j] + nums[k] - target;
          if (su == 0) {
            return target;
          } else {
            int abs_su = abs(su);
            if (abs_su < abs_best) {
              best = su;
              abs_best = abs_su;
            }
            if (su > 0) k = backward[k];
            else j = forward[j];
          }
        }
      }
      return best + target;
    }
};

int main() {
  int n;
  cin >> n;
  vector<int> vs;
  while(n--) {
    int d;
    cin >> d;
    vs.push_back(d);
  }
  int target;
  cin >> target;
  Solution so;
  int res = so.threeSumClosest(vs, target);
  cout << res << endl;
  return 0;
}
