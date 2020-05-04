#include "common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
          int mid = lo + ((hi - lo) >> 1);
          int a = nums[0] <= nums[mid];
          int b = nums[mid] <= target;
          int c = target < nums[0];
          a + b + c >= 2 ? lo = mid + 1 : hi = mid;
        }
        --lo;
        return lo == -1 ? -1 : (nums[lo] == target ? lo : -1);
    }
};

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  int target;
  cin >> target;
  cout << Solution().search(nums, target) << endl;
  return 0;
}
