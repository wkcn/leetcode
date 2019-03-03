#include "common.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      // binary search
      int lo = 0, hi = nums.size();
      while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        // lower_bound
        nums[mid] < target ? lo = mid + 1 : hi = mid;
      }
      return lo;
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  cout << Solution().searchInsert(nums, target) << endl;
  return 0;
}
